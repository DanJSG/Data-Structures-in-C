#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "Hashes.h"

typedef enum fnv_consts {
    PRIME_32 = 16777619U,
    OFFSET_32 = 2166136261U,
    PRIME_64 = 1099511628211U,
    OFFSET_64 = 14695981039346656037U
} fnv_consts;

static uint64_t fnv1a(const unsigned char* str, uint64_t prime, uint64_t offset) {
    uint64_t hash = offset;
    for(int i=0; i < strlen(str); i++) {
        hash ^= *(str + i);
        hash *= prime;
    }
    return hash;
}

uint32_t fnv1a_32(const unsigned char* str) {
    return (uint32_t)fnv1a(str, PRIME_32, OFFSET_32);
}

uint64_t fnv1a_64(const unsigned char* str) {
    return (uint64_t)fnv1a(str, PRIME_64, OFFSET_64);
}

int hashcode(const unsigned char* str) {
    unsigned int hash = 0;
    for(int i=0; i < strlen(str); i++) {
        hash = 31 * hash + (unsigned int)(*(str + i));
    }
    return hash;
}