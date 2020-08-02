
#include "queue.h"
#include <stdio.h>  // for print
#include <stdlib.h>  //  for malloc/free

// init queue
Queue *initQueue(int size){
    if (size <= 0) {
        printf("size should not be negative or zero!\n");
        return NULL;
    }
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (ElemType *)malloc(sizeof(ElemType) * size);

    if(queue->data == NULL){
        printf("size is too large!, no memory\n");
        free(queue);
        queue = NULL;
        return NULL;
    }

    queue->maxSize = size;
    queue->front = queue->rear = -1;
    return queue;
}

// destory queue
void destoryQueue(Queue *queue){
    if(queue != NULL){
        free(queue->data);
        queue->data = NULL;
        free(queue);
        queue = NULL;
    }
}


int enQueue(Queue *queue, ElemType value){
    if(queue == NULL){
        printf("queue is NULL\n");
        return -1;
    }
    // queue is full?
    if(queue->rear == queue->maxSize - 1){
        printf("queue is full!\n");
        return -2;
    }

    // en queue 
    // queue->rear++;
    ++queue->rear;
    queue->data[queue->rear] = value;
    return 1;
}

int deQueue(Queue *queue, ElemType *value){
    if(queue == NULL){
        printf("queue is NULL\n");
        return -1;
    }

    // queue is empty?
    if (queue->front == queue->rear){
        printf("queue is empty!\n");
        return -2;
    }

    ++queue->front;
    *value = queue->data[queue->front];
    return 1;
}
