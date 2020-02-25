#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Bool.h"

int upsize(ArrayList* list);
int is_array_full(ArrayList* list);

ArrayList* constructor() {
	ArrayList* list = malloc(sizeof(ArrayList));
	list->capacity = initCapacity;
	list->size = 0;
	list->array = malloc(list->capacity * sizeof(int));
	return list;
}

int get(ArrayList* list, int index) {
    if(is_array_empty(list)) {
        return NULL;
    }
    if(index > list->size - 1) {
        return NULL;
    }
    return *(list->array + index);
}

int push(ArrayList* list, int value) {
    int failure = 0;
    if(is_array_full(list)) {
        failure = upsize(list);
    }
    if(failure) {
        return 1;
    }
    *(list->array + list->size) = value;
    list->size++;
    return 0;
}

int upsize(ArrayList* list) {
    list->capacity *= resizeFactor;
    int* newList = (int*)realloc(list->array, list->capacity * sizeof(int));
    if(!newList) {
        return 1;
    }
    list->array = newList;
//    free(*newList);
    return 0;
}

void downsize(ArrayList* list) {
    list->capacity /= resizeFactor;
    realloc(list->array, list->capacity * sizeof(int));
}

int list_size(ArrayList* list) {
    return list->size;
}

int capacity(ArrayList* list) {
    return list->capacity;
}

int is_array_empty(ArrayList* list) {
    if(list->size < 1) {
        return true;
    } else {
        return false;
    }
}

int is_array_full(ArrayList* list) {
    if(list->size >= list->capacity) {
        return true;
    } else {
        return false;
    }
}

int insert_at(ArrayList* list, int index, int value) {
    int failure;
    if(index > list->size - 1) {
        return 1;
    }
    if(is_array_full(list)) {
        failure = upsize(list);
    }
    if(failure) {
        return 1;
    }
    memmove(list->array + index + 1, list->array + index, (list->size - index) * sizeof(int));
    *(list->array + index) = value;
    list->size++;
    return 0;
}

int pop(ArrayList* list) {
    if(is_array_empty(list)) {
        return -1;
    }
    int value = *(list->array + list->size - 1);
    free((int*)(list->array + list->size - 1));
    list->size--;
    if(list->size < list->capacity / resizeFactor) {
        downsize(list);
    }
    return value;
}

int delete_at(ArrayList* list, int index) {
    if(is_array_empty(list)) {
        return 1;
    }
    if(index > list->size - 1) {
        return 1;
    }
    if(index == list->size - 1) {
        pop(list);
        return 0;
    }
    memmove(list->array + index, list->array + index + 1, (list->size - index) * sizeof(int));
    list->size--;
    if(list->size < (list->capacity / resizeFactor)) {
        downsize(list);
    }
    return 0;
}

int remove_value(ArrayList* list, int value) {
    if(is_array_empty(list)) {
        return 1;
    }
    for(int i=0; i<list->size; i++) {
        if(*(list->array + i) == value) {
            delete_at(list, i);
            return 0;
        }
    }
    return 1;
}

int find_value(ArrayList* list, int value) {
    if(is_array_empty(list)) {
        return -1;
    }
    for(int i=0; i<list->size; i++) {
        if(*(list->array + i) == value) {
            return i;
        }
    }
    return -1;
}

void clear(ArrayList* list) {
    free(list->array);
    list->size = 0;
    list->capacity = 16;
    list->array = malloc(list->capacity * sizeof(int));
}

void destructor(ArrayList* list) {
    free(list->array);
    free(list);
}

void array_print(ArrayList* list) {
    for(int i=0; i<list->size; i++) {
        printf("Item %d is %d.\n", i, list->array[i]);
    }
}
