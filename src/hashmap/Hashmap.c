#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Hashmap.h"
#include "../common/Hashes.h"

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
    // TODO implement linear probing here
    // TODO implement size check and dynamic resize/reshashing here
    *(*(map->pairs + index)).key = key;
    *(*(map->pairs + index)).val = val;
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
    
}
