#include <stdio.h>
#include <stdlib.h>
#include "QNode.h"

QNode* qnode_construct(const char* msg, int length) {
    QNode* node = malloc(sizeof(QNode));
    node->msg = msg;
    node->length = length;
}

void qnode_destruct(QNode* node) {
    free(node->msg);
    free(node);
}

char* qnode_get_msg(QNode* node) {
    return node->msg;
}
int qnode_get_length(QNode* node) {
    return node->length;
}