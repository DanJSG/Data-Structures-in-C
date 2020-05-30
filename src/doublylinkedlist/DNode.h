#ifndef DNODE_H_INCLUDED
#define DNODE_H_INCLUDED

typedef struct DNode {
    int value;
    DNode* next;
    DNode* prev;
} DNode;

DNode* dnode_constructor(int value);
int dnode_get_value(DNode* node);
DNode* dnode_get_next(DNode* node);
DNode* dnode_get_prev(DNode* node);
void dnode_destructor(DNode* node);

#endif // DNODE_H_INCLUDED