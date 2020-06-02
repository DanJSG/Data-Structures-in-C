#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "../common/Bool.h"
#include "../common/ArrayConsts.h"
#include "QNode.h"

typedef struct Queue {
    int size;
    int capacity;
    int head;
    int tail;
    QNode* nodes;
} Queue;

Queue* q_construct();
void q_destruct(Queue* queue);

void q_enqueue(Queue* queue, char* msg, int length);
QNode* q_dequeue(Queue* queue);

Bool q_upsize(Queue* queue);

int q_size(Queue* queue);
Bool q_is_empty(Queue* Queue);
Bool q_is_full(Queue* queue);

void q_print(Queue* queue);

#endif //QUEUE_H_INCLUDED