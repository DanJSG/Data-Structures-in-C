#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* node_constructor(int value);
int node_get_value(Node* node);
Node* node_get_next(Node* node);
void node_destructor(Node* node);

#endif // NODE_H_INCLUDED
