#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node* node_constructor(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

int node_get_value(Node* node) {
    return node->value;
}

Node* node_get_next(Node* node) {
    return node->next;
}

void node_destructor(Node* node) {
    free(node);
}
