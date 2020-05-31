#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "QNode.h"

Queue* q_construct() {
    Queue* queue = malloc(sizeof(queue));
    queue->nodes = malloc(sizeof(QNode) * INIT_CAPACITY);
    queue->capacity = INIT_CAPACITY;
    queue->size = 0;
    return queue;
}

void q_destruct(Queue* queue) {
    free(queue->nodes);
    free(queue);
}

void q_enqueue(Queue* queue, const char* msg, int length) {
    QNode* node = qnode_construct(msg, length);
}

QNode* q_dequeue(Queue* queue);

int q_size(Queue queue);
Bool q_is_empty(Queue Queue)


// X X X X
// A
// A B
// A B C