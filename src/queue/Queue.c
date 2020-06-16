#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#include "QNode.h"

#define INIT_CAPACITY       (1 << 4)
#define RESIZE_FACTOR       (2)

#define Q_IS_EMPTY(queue)   (queue->size == 0 ? true : false)
#define Q_IS_FULL(queue)    (queue->size == queue->capacity ? true : false)

Bool q_upsize(Queue* queue);

Queue* q_construct() {
    Queue* queue = malloc(sizeof(queue));
    queue->nodes = malloc(sizeof(QNode) * INIT_CAPACITY);
    queue->head = -1;
    queue->tail = -1;
    queue->capacity = INIT_CAPACITY;
    queue->size = 0;
    return queue;
}

void q_destruct(Queue* queue) {
    free(queue->nodes);
    free(queue);
}

void q_enqueue(Queue* queue, char* msg) {
    Bool upsized;
    if(Q_IS_FULL(queue)) upsized = q_upsize(queue);
    if(!upsized) return;
    if(Q_IS_EMPTY(queue)) queue->head++;
    queue->tail = (queue->tail + 1) % queue->capacity;
    (*(queue->nodes + queue->tail)).length = strlen(msg);
    strcpy((*(queue->nodes + queue->tail)).msg, msg);
    queue->size++;
}

QNode* q_dequeue(Queue* queue) {
    if(Q_IS_EMPTY(queue)) return NULL;
    QNode* node = queue->nodes + queue->head;
    if(queue->head == queue->tail) {
        queue->tail == -1;
        queue->head == -1;
    } else {
        queue->head = (queue->head + 1) % queue->capacity;
    }
    queue->size--;
    return node;
}

int q_size(Queue* queue) {
    return queue->size;
}

Bool q_upsize(Queue* queue) {
    int init_size = queue->size;
    queue->capacity *= RESIZE_FACTOR;
    QNode* new_nodes = realloc(queue->nodes, queue->capacity * sizeof(QNode));
    if(!new_nodes) return false;
    queue->nodes = new_nodes;
    if(queue->head < queue->tail) return true;
    for(int i=queue->head; i < init_size; i++) 
        *(queue->nodes + i + init_size) = *(queue->nodes + i);
    queue->head = queue->head + init_size;
    return true;
}

void q_print(Queue* queue) {
    int i;
    for(i=queue->head; i != queue->tail; i = (i + 1) % queue->capacity)
        printf("Item at index %d contains message %s of length %lu\n", i, (*(queue->nodes + i)).msg, (*(queue->nodes + i)).length);
    printf("Item at index %d contains message %s of length %lu\n", i, (*(queue->nodes + i)).msg, (*(queue->nodes + i)).length);
}
