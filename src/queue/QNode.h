#ifndef QNODE_H_INCLUDED
#define QNODE_H_INCLUDED

typedef struct QNode {
    char* msg;
    int length;
} QNode;

QNode* qnode_construct(const char* msg, int length);
void qnode_destruct(QNode* node);
char* qnode_get_msg(QNode* node);
int qnode_get_length(QNode* node);

#endif //QNODE_H_INCLUDED