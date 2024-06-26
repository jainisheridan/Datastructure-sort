#ifndef __queue_h__
#define __queue_h__

typedef struct node_def{
}Node;

typedef struct{
}Queue;

void initQueue(Queue*);
char dequeue(Queue*);
void enqueue(Queue*, int);
void printQueue(Queue*);

#endif
