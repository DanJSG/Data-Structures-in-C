#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "../common/Bool.h"
#include "QNode.h"

/** Data type for a queue implemented using a circular array. */
typedef struct Queue {
    size_t size;
    int capacity;
    int head;
    int tail;
    QNode* nodes;
} Queue;

/** Construct a new queue and allocate memory. */
Queue* q_construct();
/** Queue destructor which frees the memory. */
void q_destruct(Queue* queue);
/** Push an item to the tail position of the queue. */
void q_enqueue(Queue* queue, char* msg);
/** Pop an item from the head position of the queue. */
QNode* q_dequeue(Queue* queue);
/** Returns the size of the queue. */
int q_size(Queue* queue);
/** Prints the queue. */
void q_print(Queue* queue);

#endif //QUEUE_H_INCLUDED