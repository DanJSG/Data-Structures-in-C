#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "QNode.h"

Queue* q_construct() {
    Queue* queue = malloc(sizeof(queue));
    queue->nodes = malloc(sizeof(QNode) * INIT_CAPACITY);
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = INIT_CAPACITY;
    queue->size = 0;
    return queue;
}

void q_destruct(Queue* queue) {
    free(queue->nodes);
    free(queue);
}

void q_enqueue(Queue* queue, const char* msg, int length) {
    Bool upsized;
    if(q_is_full(queue)) {
        Bool upsized = q_upsize(queue);
    }
    if(!upsized) return;
    QNode* node = qnode_construct(msg, length);
    *(queue->nodes + queue->tail) = *node;
    queue->tail++;
    queue->size++;
}

QNode* q_dequeue(Queue* queue);

int q_size(Queue* queue) {
    return queue->size;
}

Bool q_is_empty(Queue* queue) {
    if(queue->size == 0) return true;
    return false;
}

Bool q_is_full(Queue* queue) {
    if(queue->size == queue->capacity) return true;
    return false;
}

Bool q_upsize(Queue* queue) {
    int init_size = queue->size;
    queue->capacity *= RESIZE_FACTOR;
    QNode* new_nodes = (QNode*)realloc(queue->nodes, queue->capacity * sizeof(QNode));
    if(!new_nodes) return false;
    queue->nodes = new_nodes;
    if(queue->head < queue->tail) return true;
    for(int i=queue->head; i < init_size; i++) {
        *(queue->nodes + i + init_size) = *(queue->nodes + i);
    }
    queue->head = queue->head + init_size;
    return true;
}
