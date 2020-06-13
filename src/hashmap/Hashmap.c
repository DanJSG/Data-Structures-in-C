#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "Hashmap.h"
#include "../common/Hashes.h"

void hashmap_resize(Hashmap* map);
void hashmap_delete_at(Hashmap* map, int index);

Hashmap* hashmap_construct() {
    Hashmap* map = malloc(sizeof(Hashmap));
    map->capacity = MAP_INIT_CAPACITY;
    map->size = 0;
    map->pairs = malloc(sizeof(Pair) * map->capacity);
    map->used_indexes = malloc(sizeof(int) * map->capacity);
    return map;
}

void hashmap_put(Hashmap* map, char* key, char* val) {
    int index = ((int) fnv1a_32(key)) % map->capacity;

    // TODO implement size check and dynamic resize/reshashing here

    if(hashmap_is_full(map)) {
        
    }

    if((*(map->pairs + index)).used) {
        while((*(map->pairs + index)).used) {
            if(strcmp((*(map->pairs + index)).key, key) == 0) {
                strcpy((*(map->pairs + index)).val, val);
                return;
            }
            if(index >= map->capacity - 1)
                index = 0;
            else
                index++;
        }
    }

    strcpy((*(map->pairs + index)).key, key);
    strcpy((*(map->pairs + index)).val, val);
    (*(map->pairs + index)).used = true;
    *(map->used_indexes + map->size) = index;
    map->size++;
}

char* hashmap_get(Hashmap* map, char* key) {
    int index = ((int) fnv1a_32(key)) % map->capacity;
    char* val = (*(map->pairs + index)).val;
    // TODO include key comparison and linear lookup to work with linear probing
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

Bool hashmap_is_full(Hashmap* map) {
    return map->size == map->capacity ? true : false;
}

void hashmap_resize(Hashmap* map) {
    size_t init_size = map->size;
    map->capacity *= MAP_RESIZE_FACTOR;
    Pair* new_pairs = (Pair*) malloc(map->capacity * sizeof(Pair));
    int* new_index_list = (int*) malloc(map->capacity * sizeof(int));
    for(int i=0; i < map->size; i++) {
        Pair curr = map->pairs[map->used_indexes[i]];
        uint32_t index = fnv1a_32((unsigned char)map->pairs[map->used_indexes[i]].key) % map->capacity;
        strcpy(*(new_pairs[index]).key, curr.key);
        strcpy(*(new_pairs[index]).val, curr.val);
        new_pairs[index].used = true;
        new_index_list[i] = index;
    }
    free(map->pairs);
    free(map->used_indexes);
    map->pairs = new_pairs;
    map->used_indexes = new_index_list;
}
