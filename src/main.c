#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include "./queue/Queue.h"
#include "./queue/QNode.h"


int main() {
    // int total = 50000000;
    
    // clock_t arr_start = clock();
    // ArrayList* arr = arr_constructor();
    // int arr_val;
    // for(int i=0; i < total; i++) {
    //     arr_insert_at(arr, 0, 10);
    // }
    // for(int i=0; i < total; i++) {
    //     arr_val = arr_get(arr, 0);
    // }
    // clock_t arr_end = clock();
    // double arr_exec_time = ((double)(arr_end - arr_start)) / CLOCKS_PER_SEC;

    // clock_t list_start = clock();
    // DoublyLinkedList* list = dlist_constructor();
    // int list_val;
    // for(int i=0; i < total; i++) {
    //     dlist_push_front(list, 10);
    // }
    // for(int i=0; i < total; i++) {
    //     list_val = dlist_pop_front(list);
    // }
    // clock_t list_end = clock();
    // double list_exec_time = ((double)(list_end - list_start)) / CLOCKS_PER_SEC;

    // printf("List execution time: %lf\n", list_exec_time);
    // printf("Array execution time: %lf\n", arr_exec_time);

    srand(time(NULL));
    char* alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    Queue* q = q_construct();
    for(int i=0; i < 16; i++) {
        char new_str[8] = "";
        for(int i=0; i < 8; i++) {
            int al_char = rand() % 52;
            strncat(new_str, alpha + al_char, 1);
        }
        q_enqueue(q, new_str, strlen(new_str));
    }

    q_print(q);

    for(int i=0; i < 8; i++) {
        QNode* out = q_dequeue(q);
        printf("Output of %d is %s\n", i, out->msg);
    }

    q_print(q);
        for(int i=0; i < 8; i++) {
        char new_str[8] = "";
        for(int i=0; i < 8; i++) {
            int al_char = rand() % 52;
            strncat(new_str, alpha + al_char, 1);
        }
        q_enqueue(q, new_str, strlen(new_str));
    }
    
    q_print(q);

    exit(0);
}
