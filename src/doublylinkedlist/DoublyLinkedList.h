#ifndef DOUBLYLINKEDLIST_H_INCLUDE
#define DOUBLYLINKEDLIST_H_INCLUDE
#include "DNode.h"
#include "../common/Bool.h"

typedef struct DoublyLinkedList {
    int size;
    DNode* head;
    DNode* tail;
} DoublyLinkedList;

DoublyLinkedList* dlist_constructor();
void dlist_push_back(DoublyLinkedList* list, int value);
void dlist_push_front(DoublyLinkedList* list, int value);
void dlist_insert_at(DoublyLinkedList* list, int value, int position);
void dlist_print(DoublyLinkedList* list);
int dlist_get(DoublyLinkedList* list, int index);
int dlist_is_empty(const DoublyLinkedList* list);
int dlist_pop_front(DoublyLinkedList* list);
int dlist_pop_back(DoublyLinkedList* list);
void dlist_delete(DoublyLinkedList* list, int index);
void dlist_remove_value(DoublyLinkedList* list, int value);
int dlist_size(const DoublyLinkedList* list);
void dlist_destructor(DoublyLinkedList* list);

#endif //DOUBLYLINKEDLIST_H_INCLUDE
