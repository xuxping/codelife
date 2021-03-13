

#include <stdio.h> // printf
#include <stdlib.h>  // malloc/free

typedef struct Box {
    int i;
    int j;
    int pre;
}Box;

typedef Box ElemType;

typedef struct Queue{
    ElemType *data;
    int maxSize;
    int front;
    int rear;
}Queue;

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

const int M = 4;
const int N = 4;


void displayPath(Queue *queue, int pre){
    if (pre != -1){
        displayPath(queue, queue->data[pre].pre);
        printf("i = %d, j = %d\n", queue->data[pre].i, queue->data[pre].j);
    }
}

// (xs, ys) -> (xe, ye), s->start, e->end
// if find, print
int mgpath(int mg[M + 2][N + 2], int xs, int ys, int xe, int ye){
    int find = 0;
    Queue *queue = initQueue(100);

    Box box;
    box.i = xs;
    box.j = ys;
    box.pre = -1;
    enQueue(queue, box);
    mg[xs][ys] = -1;

    int xi, yi, xt, yt;
    xi = xs;
    yi = ys;

    while (queue->rear != queue->front)
    {
        deQueue(queue, &box);
        xi = box.i;
        yi = box.j;
        // printf("xi==%d, yi == %d\n", xi, yi);
        // find 
        if(xi == xe && yi == ye){
            displayPath(queue, queue->front);
            find = 1;
            break;
        }
        // (xi, yi)
        // not find
        for(int i = 0; i < 4; ++i){
            switch (i)
            {
            case 0: // up
                xt = xi - 1;
                yt = yi;
                break;
            case 1: // right
                xt = xi;
                yt = yi + 1;
                break;
            case 2: // down
                xt = xi + 1;
                yt = yi;
                break;
            case 3: // left
                xt = xi;
                yt = yi - 1;
                break;
            }
            // -1, 1
            if (mg[xt][yt] == 0){
                box.i = xt;
                box.j = yt;
                box.pre = queue->front;
                enQueue(queue, box);
                mg[xt][yt] = -1;
            }
        }
    }

    destoryQueue(queue);
    return find;
}

int main(int argc, char const *argv[])
{
    int mg[M+2][N+2]=     //M=4,N=4
        { {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}  };
    
    int find = mgpath(mg, 1,1,4,4);
    printf("find == %d\n", find);

    return 0;
}

