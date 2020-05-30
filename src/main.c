#include <stdio.h>
#include <stdlib.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include <time.h>

int main() {
    ArrayList* arr = arr_constructor();
    for(int i=0; i<101; i++) {
        arr_push(arr, i * 5);
    }
    arr_print(arr);
    arr_destructor(arr);

    SinglyLinkedList* list = slist_constructor();
    for(int i=0; i < 101; i++) {
        slist_push_front(list, i * 5);
    }
    slist_print(list);

    return 0;
}
