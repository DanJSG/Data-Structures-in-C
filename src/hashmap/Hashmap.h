#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED
#include "Pair.h"

typedef struct Hashmap {
    size_t size;
    size_t capacity;
    Pair* pairs;
    int* used_indexes;
} Hashmap;

Hashmap* hashmap_construct();
void hashmap_put(Hashmap* map, const char* key, const char* val);
char* hashmap_get(Hashmap* map, char* key);
void hashmap_remove(Hashmap* map, char* key);
void hashmap_destruct(Hashmap* map);
void hashmap_print(Hashmap* map);

#endif //HASHMAP_H_INCLUDED