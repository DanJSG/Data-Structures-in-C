#ifndef DOUBLYLINKEDLIST_H_INCLUDE
#define DOUBLYLINKEDLIST_H_INCLUDE
#include "DNode.h"

typedef struct DoublyLinkedList {
    int size;
    DNode* head;
    DNode* tail;
} DoublyLinkedList;

DoublyLinkedList* dlist_constructor();

#endif //DOUBLYLINKEDLIST_H_INCLUDE