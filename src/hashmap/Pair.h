#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED
#include "../common/Bool.h"

typedef enum PairConsts {
    STR_SIZE = 128
} PairConsts;

typedef struct Pair {
    char key[STR_SIZE];
    char val[STR_SIZE];
    Bool used;
} Pair;

#endif //PAIR_H_INCLUDED