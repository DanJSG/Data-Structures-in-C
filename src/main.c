#include <stdio.h>
#include <stdlib.h>
#include "./arraylist/ArrayList.h"
#include "./singlylinkedlist/SinglyLinkedList.h"
#include "./doublylinkedlist/DoublyLinkedList.h"
#include <time.h>

int main() {
    // ArrayList* arr = arr_constructor();
    // for(int i=0; i<101; i++) {
    //     arr_push(arr, i * 5);
    // }
    // arr_print(arr);
    // arr_destructor(arr);

    // SinglyLinkedList* list = slist_constructor();
    // for(int i=0; i < 101; i++) {
    //     slist_push_front(list, i * 5);
    // }
    // slist_print(list);

    DoublyLinkedList* dlist = dlist_constructor();
    
    dlist_push_back(dlist, 3);
    dlist_push_back(dlist, 1);
    dlist_push_back(dlist, 2);
    dlist_push_back(dlist, 3);
    dlist_push_back(dlist, 3);
    dlist_push_back(dlist, 5);
    dlist_push_back(dlist, 4);
    dlist_push_back(dlist, 3);
    dlist_push_back(dlist, 3);
    dlist_print(dlist);
    dlist_remove_value(dlist, 3);
    // dlist_remove_value(dlist, 3);
    dlist_print(dlist);
    exit(0);
}
