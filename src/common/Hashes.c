#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "Hashes.h"

// slightly slower but better distribution
uint32_t fnv1a_32(const unsigned char* str) {
    uint32_t prime = 16777619;
    uint32_t hash = 2166136261;
    for(int i=0; i < strlen(str); i++) {
        hash ^= *(str + i);
        hash *= prime;
    }
    return hash;
}


// faster but worse distribution
int hashcode(const unsigned char* str) {
    unsigned int hash = 0;
    for(int i=0; i < strlen(str); i++) {
        hash = 31 * hash + (unsigned int)(*(str + i));
    }
    return hash;
}