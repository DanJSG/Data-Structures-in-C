#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DoublyLinkedList.h"

DoublyLinkedList* dlist_constructor() {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void dlist_push_back(DoublyLinkedList* list, int value) {
    DNode* node = dnode_constructor(value);
}

