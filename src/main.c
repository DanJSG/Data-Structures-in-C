#include <stdio.h>
#include <stdlib.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include <time.h>

int main() {
    int total = 50000000;
    
    clock_t arr_start = clock();
    ArrayList* arr = arr_constructor();
    int arr_val;
    for(int i=0; i < total; i++) {
        arr_insert_at(arr, 0, 10);
    }
    for(int i=0; i < total; i++) {
        arr_val = arr_get(arr, 0);
    }
    clock_t arr_end = clock();
    double arr_exec_time = ((double)(arr_end - arr_start)) / CLOCKS_PER_SEC;

    clock_t list_start = clock();
    DoublyLinkedList* list = dlist_constructor();
    int list_val;
    for(int i=0; i < total; i++) {
        dlist_push_front(list, 10);
    }
    for(int i=0; i < total; i++) {
        list_val = dlist_pop_front(list);
    }
    clock_t list_end = clock();
    double list_exec_time = ((double)(list_end - list_start)) / CLOCKS_PER_SEC;

    printf("List execution time: %lf\n", list_exec_time);
    printf("Array execution time: %lf\n", arr_exec_time);

    exit(0);
}
