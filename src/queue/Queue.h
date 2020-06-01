#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "../common/Bool.h"

typedef enum QConsts {
    INIT_CAPACITY = 16,
    RESIZE_FACTOR = 2
} QConsts;

typedef struct Queue {
    int size;
    int capacity;
    int head;
    int tail;
    QNode* nodes;
} Queue;

Queue* q_construct();
void q_destruct(Queue* queue);

void q_enqueue(Queue* queue);
QNode* q_dequeue(Queue* queue);

int q_size(Queue queue);
Bool q_is_empty(Queue Queue)

#endif //QUEUE_H_INCLUDED