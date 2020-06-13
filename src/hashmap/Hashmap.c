#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "Hashmap.h"
#include "../common/Hashes.h"

#define MAP_INIT_CAPACITY       (1 << 8)
#define MAP_RESIZE_FACTOR       (2)
#define HASHMAP_IS_FULL(map)    (map->size == map->capacity ? 1 : 0)

Bool hashmap_resize(Hashmap* map);
void hashmap_delete_at(Hashmap* map, int index);

Hashmap* hashmap_construct() {
    Hashmap* map = malloc(sizeof(Hashmap));
    map->capacity = MAP_INIT_CAPACITY;
    map->size = 0;
    map->pairs = malloc(sizeof(Pair) * map->capacity);
    map->used_indexes = malloc(sizeof(int) * map->capacity);
    return map;
}

void hashmap_put(Hashmap* map, const char* key, const char* val) {
    int index = ((int) fnv1a_32(key)) % map->capacity;
    Bool resized;
    if(HASHMAP_IS_FULL(map)) 
        resized = hashmap_resize(map);
    if(!resized) return;
    while((*(map->pairs + index)).used) {
        if(strcmp((*(map->pairs + index)).key, key) == 0) {
            strcpy((*(map->pairs + index)).val, val);
            return;
        }
        index = index >= (map->capacity - 1) ? 0 : index + 1;
    }
    strcpy((*(map->pairs + index)).key, key);
    strcpy((*(map->pairs + index)).val, val);
    (*(map->pairs + index)).used = true;
    map->size++;
    *(map->used_indexes + map->size - 1) = index;
}

char* hashmap_get(Hashmap* map, char* key) {
    size_t init_index = ((size_t) fnv1a_32(key)) % map->capacity;
    size_t index = init_index;
    Bool has_looped = false;
    while(strcmp(map->pairs[index].key, key) != 0 && map->pairs[index].used) {
        if(index >= (map->capacity - 1)) {
            index = 0;
            has_looped = true;
            continue;
        }
        if(index == init_index && has_looped == true) 
            return NULL;
        index++;
    }
    char* val = (*(map->pairs + index)).val;
    return val;
}

void hashmap_remove(Hashmap* map, char* key) {
    int index = ((int) fnv1a_32(key) % map->capacity);
    hashmap_delete_at(map, index);
}

void hashmap_delete_at(Hashmap* map, int index) {
    memmove(map->pairs + index, map->pairs + index + 1, (map->size - index) * sizeof(Pair));
    map->size--;
}

Bool hashmap_resize(Hashmap* map) {
    printf("[REALLOCATING MEMORY]\n");
    size_t init_size = map->size;
    map->capacity *= MAP_RESIZE_FACTOR;
    Pair* new_pairs = (Pair*) malloc(map->capacity * sizeof(Pair));
    if(!new_pairs) return false;
    int* new_index_list = (int*) malloc(map->capacity * sizeof(int));
    if(!new_index_list) return false;
    for(int i=0; i < map->size; i++) {
        int current_index_dbg = map->used_indexes[i];
        Pair curr = map->pairs[map->used_indexes[i]];
        uint32_t index = fnv1a_32((unsigned char*)map->pairs[map->used_indexes[i]].key) % map->capacity;
        while(new_pairs[index].used) {
            index = index >= (map->capacity - 1) ? 0 : index + 1;
        }
        strcpy((unsigned char*)new_pairs[index].key, curr.key);
        strcpy((unsigned char*)new_pairs[index].val, curr.val);
        new_pairs[index].used = true;
        new_index_list[i] = index;
    }
    free(map->pairs);
    free(map->used_indexes);
    map->pairs = new_pairs;
    map->used_indexes = new_index_list;
    return true;
}

void hashmap_print(Hashmap* map) {
    size_t index;
    printf("Idx\tKey\tVal\n");
    printf("===================\n");
    for(int i=0; i < map->size; i++) {
        index = map->used_indexes[i];
        printf("[%lu]\t%s\t%s\n", index, map->pairs[index].key, map->pairs[index].val);
    }
    printf("===================\n");
    printf("Total entries\t%lu\n", map->size);
    printf("===================\n");
}

void hashmap_destruct(Hashmap* map) {
    free(map->pairs);
    free(map->used_indexes);
    free(map);
}
