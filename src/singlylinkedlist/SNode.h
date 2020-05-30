#ifndef SNODE_H_INCLUDED
#define SNODE_H_INCLUDED

typedef struct SNode {
    int value;
    struct SNode* next;
} SNode;

SNode* snode_constructor(int value);
int snode_get_value(SNode* node);
SNode* snode_get_next(SNode* node);
void snode_destructor(SNode* node);

#endif // SNODE_H_INCLUDED
