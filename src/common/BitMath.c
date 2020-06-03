#include <stdlib.h>
#include <stdio.h>
#include "BitMath.h"

Bool is_even(unsigned int val) {
    return ~val & 1;
}

Bool is_power_of_two(unsigned int val) {
    return !(val & val-1);
}

void swap_vals(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}