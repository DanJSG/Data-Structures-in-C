#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DoublyLinkedList.h"
#include "../common/Bool.h"

DoublyLinkedList* dlist_constructor() {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int dlist_size(const DoublyLinkedList* list) {
    return list->size;
}

int dlist_is_empty(const DoublyLinkedList* list) {
    if(dlist_size(list) == 0) {
        return true;
    }
    return false;
}

void dlist_push_back(DoublyLinkedList* list, int value) {
    DNode* node = dnode_constructor(value);
    if(dlist_is_empty(list)) {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }
    list->tail->next = node;    // the list tail's pointer to the next node, points at the new node
    node->prev = list->tail;    // the node's pointer to the prev node, points to the tail node
    list->tail = node;          // the list's tail becomes the new node
    list->size++;
}

void dlist_push_front(DoublyLinkedList* list, int value) {
    DNode* node = dnode_constructor(value);
    if(dlist_is_empty(list)) {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->size++;
}

void dlist_print(DoublyLinkedList* list) {
    // printf("In dlis_print\n");
    DNode* currentNode = list->head;
    while(currentNode->next != NULL) {
        printf("%d, ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("%d\n", currentNode->value);
}

void dlist_insert_at(DoublyLinkedList* list, int value, int position) {
    if(position >= list->size || position < 0) return;
    if(position == 0 || dlist_is_empty(list)) {
        return dlist_push_front(list, value);
    } else if(position == list->size - 1) {
        return dlist_push_back(list, value);
    }
    DNode* newNode = dnode_constructor(value);
    DNode* currentNode;
    if(position <= list->size / 2) {
        currentNode = list->head;
        for(int i=0; i < position; i++) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = list->tail;
        for(int i=dlist_size(list) - 1; i > position; i--) {
            currentNode = currentNode->prev;
        }
    }
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    currentNode->prev->next = newNode;
    currentNode->prev = newNode;
    list->size++;
}

void dlist_destructor(DoublyLinkedList* list) {
    DNode* currentNode = list->head;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
        free(currentNode->prev);
    }
    free(currentNode);
    free(list);
}

int dlist_get(DoublyLinkedList* list, int index) {
    if(index < 0 || index >= dlist_size(list)) return INT_MIN;
    DNode* currentNode;
    if(index <= list->size / 2) {
        currentNode = list->head;
        for(int i=0; i < index; i++) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = list->tail;
        for(int i=dlist_size(list) - 1; i > index; i--) {
            currentNode = currentNode->prev;
        }
    }
    return currentNode->value;
}

void dlist_delete(DoublyLinkedList* list, int index) {
    if(dlist_is_empty(list) || index < 0 || index >= dlist_size(list)) return;
    DNode* currentNode;
    if(index <= dlist_size(list) / 2) {
        currentNode = list->head;
        for(int i=0; i < index; i++) {
            currentNode = currentNode->next;
        }
    } else {
        currentNode = list->tail;
        for(int i=dlist_size(list) - 1; i > index; i--) {
            currentNode = currentNode->prev;
        }
    }
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    currentNode->next = NULL;
    currentNode->prev = NULL;
    dnode_destructor(currentNode);
}

int dlist_pop_front(DoublyLinkedList* list) {
    printf("in pop front...\n");
    if(dlist_is_empty(list)) return INT_MIN;
    DNode* node = list->head;
    int value = node->value;
    list->head->next->prev = NULL;
    list->head = list->head->next;
    dnode_destructor(node);
    return value;
}

int dlist_pop_back(DoublyLinkedList* list) {
    if(dlist_is_empty(list)) return INT_MIN;
    DNode* node = list->tail;
    int value = node->value;
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    dnode_destructor(node);
    return value;
}

// void dlist_remove_value(DoublyLinkedList* list, int value) {
//     if(dlist_is_empty(list)) return;
//     DNode* currentNode = list->head;
//     int i = 0;
//     while(currentNode->next != NULL && currentNode->value != value) {
//         printf("Getting next node...");
//         currentNode = currentNode->next;
//         i++;
//     }
//     if(currentNode->value != value) return;
//     if(i == 0) {
//         dlist_pop_front(list);
//         return;
//     } else if(i == dlist_size(list) - 1) {
//         dlist_pop_back(list);
//         return;
//     }
//     printf("Found value, removing...");
//     currentNode->prev->next = currentNode->next;
//     currentNode->next->prev = currentNode->prev;
//     dnode_destructor(currentNode);
// }