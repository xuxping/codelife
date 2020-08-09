// 迷宫求解，队列实现方式

#include <stdio.h>
#include <stdlib.h>

typedef struct Box
{
    int i;
    int j;
    int pre;
} Box;

typedef Box ElemType;

typedef struct Queue
{
    ElemType *data;
    int maxSize;
    int front; // dequeue from front
    int rear;  // enqueue from rear;
} Queue;

// init queue
Queue *initQueue(int size)
{
    if (size <= 0)
    {
        printf("size should not be negative or zero!\n");
        return NULL;
    }
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (ElemType *)malloc(sizeof(ElemType) * size);

    if (queue->data == NULL)
    {
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
void destoryQueue(Queue *queue)
{
    if (queue != NULL)
    {
        free(queue->data);
        queue->data = NULL;
        free(queue);
        queue = NULL;
    }
}

int enQueue(Queue *queue, ElemType value)
{
    if (queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }
    // queue is full?
    if (queue->rear == queue->maxSize - 1)
    {
        printf("queue is full!\n");
        return -2;
    }

    // en queue
    // queue->rear++;
    ++queue->rear;
    queue->data[queue->rear] = value;
    return 1;
}

int deQueue(Queue *queue, ElemType *value)
{
    if (queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }

    // queue is empty?
    if (queue->front == queue->rear)
    {
        printf("queue is empty!\n");
        return -2;
    }

    ++queue->front;
    *value = queue->data[queue->front];
    return 1;
}

int QueueEmpty(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        return 1;
    }
    return 0;
}

void displayPath(Queue *queue, int pre){
    if (pre != -1){
        printf("i = %d, j = %d\n", queue->data[pre].i, queue->data[pre].j);
        displayPath(queue, queue->data[pre].pre);

    }
}

const int M = 4;
const int N = 4;

// search path:(xi,yi) -> (xe,ye)
// return 1: has path
// return 0: no path
int mgpath(int mg[M + 2][N + 2], int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, di, i1, j1;
    Queue *qu = initQueue(200); //定义顺序队指针qu
    e.i = xi;
    e.j = yi;
    e.pre = -1;
    enQueue(qu, e);  //(xi,yi)进队
    mg[xi][yi] = -1; //将其赋值-1,以避免回过来重复搜索

    while (QueueEmpty(qu) != 1) //队不空循环
    {
        deQueue(qu, &e); //出队方块e
        i = e.i;
        j = e.j;
        if (i == xe && j == ye) //找到了出口,输出路径
        {
            displayPath(qu, qu->front); //调用print函数输出路径
            destoryQueue(qu);     //销毁队列
            return 1;            //找到一条路径时返回真
        }
        for (di = 0; di < 4; di++) //循环扫描每个方位
        {
            switch (di)
            {
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }
            if (mg[i1][j1] == 0)
            {
                e.i = i1;
                e.j = j1;
                e.pre = qu->front;
                enQueue(qu, e);  //(i1,j1)方块进队
                mg[i1][j1] = -1; //将其赋值-1
            }
        }
    }
    destoryQueue(qu); //销毁队列
    return 0;
}

int main(int argc, char const *argv[]){
    int mg[M + 2][N + 2] = //M=4,N=4
        {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 0, 1, 0, 0, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 1, 0, 0, 0, 1},
         {1, 1, 1, 1, 1, 1}};
    mgpath(mg, 1,1,4,4);
    return 0;
}