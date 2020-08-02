// 
// gcc -o queue queue_test.c queue.c
// 

#include "queue.h"
#include <stdio.h>

void display(Queue *queue){
    for(int i = queue->front + 1; i <= queue->rear; ++i){
        printf("%d->%d\n", i, queue->data[i]);
    }
}

int main(void){
    const int MAX_SIZE = 5;
    Queue *queue = initQueue(MAX_SIZE);

    enQueue(queue, 5);
    enQueue(queue, 4);
    enQueue(queue, 3);
    enQueue(queue, 3);
    enQueue(queue, 7);
    enQueue(queue, 6);
    enQueue(queue, 5);

    display(queue);


    int value;
    deQueue(queue, &value);
    printf("value = %d\n", value);
    display(queue);

    destoryQueue(queue);
    return 0;
}