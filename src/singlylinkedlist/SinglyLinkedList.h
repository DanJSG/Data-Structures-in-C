#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED
#include "SNode.h"

typedef struct SinglyLinkedList {
    int size;
    SNode* head;
} SinglyLinkedList;

SinglyLinkedList* slist_constructor();
void slist_push_back(SinglyLinkedList* list, int value);
void slist_push_front(SinglyLinkedList* list, int value);
int slist_insert_at(SinglyLinkedList* list, int value, int position);
void slist_print(SinglyLinkedList* list);
int slist_get(SinglyLinkedList* list, int index);
int slist_pop_front(SinglyLinkedList* list);
int slist_pop_back(SinglyLinkedList* list);
void slist_delete(SinglyLinkedList* list, int position);
int slist_remove_value(SinglyLinkedList* list, int value);
int slist_size(SinglyLinkedList* list);

#endif // SINGLYLINKEDLIST_H_INCLUDED
