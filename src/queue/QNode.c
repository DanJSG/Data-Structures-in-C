#include <stdio.h>
#include <stdlib.h>
#include "QNode.h"

char* qnode_get_msg(QNode* node) {
    return node->msg;
}
int qnode_get_length(QNode* node) {
    return node->length;
}