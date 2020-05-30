#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SinglyLinkedList.h"

SinglyLinkedList* list_constructor() {
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

void list_push_back(SinglyLinkedList* list, int value) {
    if(list_is_empty(list)) {
        list_push_front(list, value);
    }
    Node* newNode = node_constructor(value);
    Node* currentNode = list->head;
    while(currentNode->next) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    list->size++;
}

void list_push_front(SinglyLinkedList* list, int value) {
    Node* newNode = node_constructor(value);
    if(list_is_empty(list)) {
        list->head = newNode;
        list->size++;
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

int list_insert_at(SinglyLinkedList* list, int value, int position) {
    if(position > list->size || position < 0) {
        return 1;
    }
    Node* newNode = node_constructor(value);
    if(position == 0 || list_is_empty(list)) {
        list_push_front(list, value);
        return 0;
    }
    if(position == list_size(list) - 1) {
        list_push_back(list, value);
        return 0;
    }
    Node* currentNode = list->head;
    for(int i=0; i<position - 2; i++) {
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    list->size++;
    return 0;
}

int list_get(SinglyLinkedList* list, int index) {
    if(list_is_empty(list)) {
        return INT_MIN;
    }
    Node* currentNode = list->head;
    for(int i=0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->value;
}

int list_pop_front(SinglyLinkedList* list) {
    int value = list->head->value;
    Node* oldNode = list->head;
    list->head = list->head->next;
    node_destructor(oldNode);
    oldNode = NULL;
    list->size--;
    return value;
}

void list_delete(SinglyLinkedList* list, int position) {
    if(list_is_empty(list)) {
        return;
    }
    if(position >= list_size(list)) {
        return;
    }
    Node* currentNode = list->head;
    Node* prevNode;
    for(int i=0; i<position - 1; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = currentNode->next;
    node_destructor(currentNode);
    currentNode = NULL;
    list->size--;
}

int list_pop_back(SinglyLinkedList* list) {
    Node* currentNode = list->head;
    Node* prevNode;
    int output;
    while(currentNode) {
        if(currentNode->next == NULL) {
            output = currentNode->value;
            prevNode->next = NULL;
            node_destructor(currentNode);
            currentNode = NULL;
            break;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    list->size--;
    return output;
}


void list_print(SinglyLinkedList* list) {
    if(list_is_empty(list)) {
        printf("\nList is empty.\n");
        return;
    }
    Node* currentNode = list->head;
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

int list_remove_value(SinglyLinkedList* list, int value) {
    if(list_is_empty(list)) {
        return 1;
    }
    Node* currentNode = list->head;
    Node* prevNode;
    while(currentNode->value != value && currentNode->next != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode->value != value) {
        return 1;
    }
    prevNode->next = currentNode->next;
    node_destructor(currentNode);
    currentNode = NULL;
    return 0;
}

int list_size(SinglyLinkedList* list) {
    return list->size;
}

int list_is_empty(SinglyLinkedList* list) {
    if(list_size(list) == 0) {
        return 1;
    }
    return 0;
}

