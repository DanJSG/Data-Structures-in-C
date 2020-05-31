#include <stdio.h>
#include <stdlib.h>
#include "DNode.h"

DNode* dnode_constructor(int value) {
    DNode* node = malloc(sizeof(DNode));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int dnode_get_value(DNode* node) {
    return node->value;
}

DNode* dnode_get_next(DNode* node) {
    return node->next;
}

DNode* dnode_get_prev(DNode* node) {
    return node->prev;
}

void dnode_destructor(DNode* node) {
    node->next = NULL;
    node->next = NULL;
    free(node);
}