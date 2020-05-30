#include <stdio.h>
#include <stdlib.h>
#include "SNode.h"

SNode* snode_constructor(int value) {
    SNode* node = malloc(sizeof(SNode));
    node->value = value;
    node->next = NULL;
    return node;
}

int snode_get_value(SNode* node) {
    return node->value;
}

SNode* snode_get_next(SNode* node) {
    return node->next;
}

void snode_destructor(SNode* node) {
    free(node);
}
