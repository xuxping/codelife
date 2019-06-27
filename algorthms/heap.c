// 最大堆的实现和堆排序

#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

struct Heap{
     int *heap; // 堆指针
     int len; // 数组长度
     int size; // 队列的长度
};


// 获取父节点
int parent(i)
{
    return i / 2;
}

// 获取左孩子节点
int left(i)
{
    return 2 * i;
}

// 获取右孩子节点
int right(i)
{
    return 2 * i + 1;
}


// 堆平衡
void max_heapify(struct Heap *h, int i)
{
    int l = left(i);
    int r = right(i);
    int large = i;
    int tmp = 0;
    // 找到最大的节点
    if (l < h->size && h->heap[l] > h->heap[i])
    {
        large = l;
    }
    else
    {
        large = i;
    }
    if (r < h->size && h->heap[r] > h->heap[large])
    {
        large = r;
    }
    // 进行交换
    if (large != i)
    {
        tmp = h->heap[i];
        h->heap[i] = h->heap[large];
        h->heap[large] = tmp;
        max_heapify(h, large);
    }
}

// 构建最大堆
void buid_max_heap(struct Heap *h)
{
    printf("build max heap\n");
    h->size = h->len;
    // 从下往上构建堆
    for (int i = h->size / 2; i >= 0; i--)
    {
        max_heapify(h, i);
    }
    display(h->heap, h->len);
}

// 堆排序 O(lgn)
void headpsort(struct Heap *h)
{
    // buid_max_heap(h);
    printf("heap sort result:\n");
    int tmp = 0;
    for (int i = h->size - 1; i >= 1; i--)
    {
        // 将堆最后一个与第一个进行交换
        tmp = h->heap[i];
        h->heap[i] = h->heap[0];
        h->heap[0] = tmp;

        h->size -= 1;
        max_heapify(h, 0);
    }
    display(h->heap, h->len);
}

// 弹出一个元素
int pop(struct Heap *h)
{
    if (h->size == 0)
    {
        return -1; // 应该用一个其它值代替
    }
    h->size = h->size - 1;

    int data = h->heap[0];
    // 将最后一个数据放置在第一个，进行平衡
    h->heap[0] = h->heap[h->size];
    // 将尾部置为-1
    h->heap[h->size] = -1;
    // 平衡
    max_heapify(h, 0);
    printf("pop data:%d\n", data);
    display(h->heap, h->len);
    return data;
}

void push(struct Heap *h, int node)
{
    // 堆满了
    if (h->len == h->size){
        return; 
    }
    printf("push data:%d\n",node);
    h->size += 1;
    int lastIdx = h->size - 1;
    int parentIdx = parent(lastIdx);
    h->heap[lastIdx] = node;
    while (lastIdx > 0 && h->heap[parentIdx] < h->heap[lastIdx]){
        //交换两个节点
        int tmp = h->heap[parentIdx];
        h->heap[parentIdx] = h->heap[lastIdx];
        h->heap[lastIdx] = tmp;

        // 交换idx
        lastIdx = parentIdx;
        parentIdx = parent(parentIdx);
    }
    display(h->heap, h->len);
}

int main(void)
{
    struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
    if (h == NULL)
    {
        printf("[error] no memory to malloc for heap!");
        exit(-1);
    } 
    h->len = 10;
    h->heap = (int *)malloc(sizeof(int) * h->len);
    h->size = 10;
    for (int i = 0; i < h->len; i++)
    {
        h->heap[i] = rand_idx(0, 20);
    }
    printf("heap size:%d\n",h->size);
    display(h->heap, h->size);

    buid_max_heap(h);

    headpsort(h);

    buid_max_heap(h);

    int data1 = pop(h);

    int data2 = pop(h);

    push(h, data1);
    push(h, data2);

    printf("h->size: %d\n", h->size);

    free(h->heap);
    free(h);
    return 0;
}
