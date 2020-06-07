#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED
#include "Pair.h"

typedef enum MapConsts {
    MAP_INIT_CAPACITY = 256,
    MAP_RESIZE_FACTOR = 2
} MapConsts;

typedef struct Hashmap {
    size_t size;
    size_t capacity;
    Pair* pairs;
    int* used_indexes;
} Hashmap;

Hashmap* hashmap_construct();
void hashmap_put(Hashmap* map, char* key, char* val);
char* hashmap_get(Hashmap* map, char* key);
void hashmap_remove(Hashmap* map, char* key);
void hashmap_destruct(Hashmap*);

#endif //HASHMAP_H_INCLUDED