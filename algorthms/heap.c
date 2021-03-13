/**
 * 堆是一种近似的完全二叉树，除了最底层，树是完全充满的，而且是从左到右
 * 
 * 最大堆：除了根以外的所有节点都满足，某个节点的值小于等于其父节点，根节点是最大的；
 * 最小堆：除了根以外的所有节点都满足，某个节点的值大于等于其父节点，根节点是最小的
 * 
 * 主要应用：
 * 优先级队列，高性能定时器
 * 
 * 常见算法题：
 * 1、堆排序
 * 2、合并K个链表或文件
 * 3、topK
 * 4、流里面的中值、中位数：
 * 维护两个堆，一个大顶堆，一个小顶堆。大顶堆中存储前半部分数据，
 * 小顶堆中存储后半部分数据，且小顶堆中的数据都大于大顶堆中的数据。
 * 5、看如何求 99% 响应时间
 * 维护两个堆，一个大顶堆，一个小顶堆。假设当前总数据的个数是 n，
 * 大顶堆中保存 n*99% 个数据，小顶堆中保存 n*1% 个数据。
 * 大顶堆堆顶的数据就是我们要找的 99% 响应时间。
 **/


// 最大堆的实现和堆排序
#include "util.h"
#include <stdio.h>
#include <stdlib.h>


// 堆一般采用数组来实现，原地处理
struct Heap{
     int *heap; // 堆指针
     int len; // 数组长度
     int size; // 记录heap的初始大小
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
    // 从下往上构建堆，从数组中间开始
    for (int i = h->size / 2; i >= 0; i--)
    {
        max_heapify(h, i);
    }
    display(h->heap, h->len);
}

/**
 * 堆排序 O(nlgn)
 * 堆排序数据访问的方式没有快速排序友好, 局部顺序访问，所以，这样对 CPU 缓存是不友好的。
 * 对于同样的数据，在排序过程中，堆排序算法的数据交换次数要多于快速排序
 **/  
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
    /**
     * 将数据插入到堆的最后，然后在向上进行平衡
     */
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

void freeHeap(struct Heap *h){
    if (h != NULL){
        if (h->heap){
            free(h->heap);
        }
        free(h);
    }

}

/**
 * init a heap by hsize
 */
struct Heap *initHeap(int hsize){
    struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
    if (h == NULL)
    {
        printf("[error] no memory to malloc for heap!");
        exit(-1);
    } 
    h->len = hsize;
    h->heap = (int *)malloc(sizeof(int) * h->len);
    h->size = 0;
    
    for (int i = 0; i < h->len; i++)
    {
        h->heap[i] = -1;
    }
    return h;
}