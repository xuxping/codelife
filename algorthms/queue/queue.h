
#ifndef QUEUE_H
#define QUEUE_H

typedef int ElemType;

typedef struct Queue{
    ElemType *data;
    int maxSize;
    int front; // dequeue from front
    int rear;  // enqueue from rear;
}Queue;


Queue *initQueue(int size);
void destoryQueue(Queue *queue);
int enQueue(Queue *queue, ElemType value);
int deQueue(Queue *queue, ElemType *value);

#endif