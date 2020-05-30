#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED
#include "Node.h"

typedef struct SinglyLinkedList {
    int size;
    Node* head;
} SinglyLinkedList;

SinglyLinkedList* list_constructor();
void list_push_back(SinglyLinkedList* list, int value);
void list_push_front(SinglyLinkedList* list, int value);
int list_insert_at(SinglyLinkedList* list, int value, int position);
void list_print(SinglyLinkedList* list);
int list_get(SinglyLinkedList* list, int index);
int list_is_empty(SinglyLinkedList* list);
int list_pop_front(SinglyLinkedList* list);
int list_pop_back(SinglyLinkedList* list);
void list_delete(SinglyLinkedList* list, int position);
int list_remove_value(SinglyLinkedList* list, int value);
int list_size(SinglyLinkedList* list);

#endif // SINGLYLINKEDLIST_H_INCLUDED
