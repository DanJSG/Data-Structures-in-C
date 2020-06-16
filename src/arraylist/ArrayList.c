#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ArrayList.h"
#include "../common/Bool.h"

#define INIT_CAPACITY   16
#define RESIZE_FACTOR   2

int upsize(ArrayList* list);
int is_array_full(ArrayList* list);

ArrayList* arr_constructor() {
	ArrayList* list = malloc(sizeof(ArrayList));
	list->capacity = INIT_CAPACITY;
	list->size = 0;
	list->array = malloc(list->capacity * sizeof(int));
	return list;
}

int arr_get(ArrayList* list, int index) {
    if(arr_is_empty(list)) {
        return INT_MIN;
    }
    if(index > list->size - 1) {
        return INT_MIN;
    }
    return *(list->array + index);
}

int arr_push(ArrayList* list, int value) {
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
    list->capacity *= RESIZE_FACTOR;
    int* newList = (int*)realloc(list->array, list->capacity * sizeof(int));
    if(!newList) {
        return 1;
    }
    list->array = newList;
    return 0;
}

void downsize(ArrayList* list) {
    list->capacity /= RESIZE_FACTOR;
    list->array = realloc(list->array, list->capacity * sizeof(int));
    if(!list->array) exit(1);
}

int arr_size(ArrayList* list) {
    return list->size;
}

int arr_capacity(ArrayList* list) {
    return list->capacity;
}

int arr_is_empty(ArrayList* list) {
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

int arr_insert_at(ArrayList* list, int index, int value) {
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

int arr_pop(ArrayList* list) {
    if(arr_is_empty(list)) {
        return -1;
    }
    int value = *(list->array + list->size - 1);
    free((int*)(list->array + list->size - 1));
    list->size--;
    if(list->size < list->capacity / RESIZE_FACTOR) {
        downsize(list);
    }
    return value;
}

int arr_delete_at(ArrayList* list, int index) {
    if(arr_is_empty(list)) {
        return 1;
    }
    if(index > list->size - 1) {
        return 1;
    }
    if(index == list->size - 1) {
        arr_pop(list);
        return 0;
    }
    memmove(list->array + index, list->array + index + 1, (list->size - index) * sizeof(int));
    list->size--;
    if(list->size < (list->capacity / RESIZE_FACTOR)) {
        downsize(list);
    }
    return 0;
}

int arr_remove_value(ArrayList* list, int value) {
    if(arr_is_empty(list)) {
        return 1;
    }
    for(int i=0; i<list->size; i++) {
        if(*(list->array + i) == value) {
            arr_delete_at(list, i);
            return 0;
        }
    }
    return 1;
}

int arr_find_value(ArrayList* list, int value) {
    if(arr_is_empty(list)) {
        return -1;
    }
    for(int i=0; i<list->size; i++) {
        if(*(list->array + i) == value) {
            return i;
        }
    }
    return -1;
}

void arr_clear(ArrayList* list) {
    free(list->array);
    list->size = 0;
    list->capacity = 16;
    list->array = malloc(list->capacity * sizeof(int));
}

void arr_destructor(ArrayList* list) {
    free(list->array);
    free(list);
}

void arr_print(ArrayList* list) {
    for(int i=0; i<list->size; i++) {
        printf("Item %d is %d.\n", i, list->array[i]);
    }
}
