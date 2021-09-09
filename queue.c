#include <stdlib.h>
#include "queue.h"

void initialize(queue *q) {
    q->first = 0;
    q->last = 0;
}

void destroy(queue *q) {
    while(!empty(q))
        pop(q);
}

void* front(queue *q) {
    if(!empty(q))
        return q->first->data;
    return 0;
}

void push(queue *q, void* data) {
    qnode *node = (qnode*)malloc(sizeof(qnode));
    node->data = data;
    node->next = 0;

    if (empty(q)) {
        q->first = node;
    } else {
        q->last->next = node;
    }
    q->last = node;
    
}

void pop(queue *q) {
    if (!empty(q)) {
        qnode *node = q->first;
        q->first = q->first->next;
        free(node);
    }
        
}

int empty(queue *q) {
    return q->first == 0;
}