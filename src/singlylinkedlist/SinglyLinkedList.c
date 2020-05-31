#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SinglyLinkedList.h"
#include "../common/Bool.h"

SinglyLinkedList* slist_constructor() {
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

void slist_push_back(SinglyLinkedList* list, int value) {
    if(slist_is_empty(list)) {
        slist_push_front(list, value);
    }
    SNode* newNode = snode_constructor(value);
    SNode* currentNode = list->head;
    while(currentNode->next) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    list->size++;
}

void slist_push_front(SinglyLinkedList* list, int value) {
    SNode* newNode = snode_constructor(value);
    if(slist_is_empty(list)) {
        list->head = newNode;
        list->size++;
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

int slist_insert_at(SinglyLinkedList* list, int value, int position) {
    if(position > list->size || position < 0) {
        return 1;
    }
    SNode* newNode = snode_constructor(value);
    if(position == 0 || slist_is_empty(list)) {
        slist_push_front(list, value);
        return 0;
    }
    if(position == slist_size(list) - 1) {
        slist_push_back(list, value);
        return 0;
    }
    SNode* currentNode = list->head;
    for(int i=0; i<position - 2; i++) {
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    list->size++;
    return 0;
}

int slist_get(SinglyLinkedList* list, int index) {
    if(slist_is_empty(list)) {
        return INT_MIN;
    }
    SNode* currentNode = list->head;
    for(int i=0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->value;
}

int slist_pop_front(SinglyLinkedList* list) {
    int value = list->head->value;
    SNode* oldNode = list->head;
    list->head = list->head->next;
    snode_destructor(oldNode);
    oldNode = NULL;
    list->size--;
    return value;
}

void slist_delete(SinglyLinkedList* list, int position) {
    if(slist_is_empty(list)) {
        return;
    }
    if(position >= slist_size(list)) {
        return;
    }
    SNode* currentNode = list->head;
    SNode* prevNode;
    for(int i=0; i<position - 1; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = currentNode->next;
    snode_destructor(currentNode);
    currentNode = NULL;
    list->size--;
}

int slist_pop_back(SinglyLinkedList* list) {
    SNode* currentNode = list->head;
    SNode* prevNode;
    int output;
    while(currentNode) {
        if(currentNode->next == NULL) {
            output = currentNode->value;
            prevNode->next = NULL;
            snode_destructor(currentNode);
            currentNode = NULL;
            break;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    list->size--;
    return output;
}


void slist_print(SinglyLinkedList* list) {
    if(slist_is_empty(list)) {
        printf("\nList is empty.\n");
        return;
    }
    SNode* currentNode = list->head;
    int count = 0;
    printf("[");
    while(currentNode) {
        if(currentNode != list->head) {
            printf(", ");
        }
        printf("%d", currentNode->value);
        currentNode = currentNode->next;
        count++;
    }
    printf("]\n");
}

int slist_remove_value(SinglyLinkedList* list, int value) {
    if(slist_is_empty(list)) {
        return 1;
    }
    SNode* currentNode = list->head;
    SNode* prevNode;
    while(currentNode->value != value && currentNode->next != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode->value != value) {
        return 1;
    }
    prevNode->next = currentNode->next;
    snode_destructor(currentNode);
    currentNode = NULL;
    return 0;
}

int slist_size(SinglyLinkedList* list) {
    return list->size;
}

int slist_is_empty(SinglyLinkedList* list) {
    if(slist_size(list) == 0) {
        return true;
    }
    return false;
}
