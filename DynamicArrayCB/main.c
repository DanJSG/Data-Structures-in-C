#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include <time.h>

int main() {
    ArrayList* list = constructor();
    for(int i=0; i<10000001; i++) {
        push(list, i * 5);
    }
    destructor(list);
    return 0;
}
