#ifndef QNODE_H_INCLUDED
#define QNODE_H_INCLUDED

typedef enum QNodeConstants {
    MSG_MAX_CHAR = 255
} QNodeConstants;

typedef struct QNode {
    char msg[MSG_MAX_CHAR];
    size_t length;
} QNode;

char* qnode_get_msg(QNode* node);
int qnode_get_length(QNode* node);

#endif //QNODE_H_INCLUDED