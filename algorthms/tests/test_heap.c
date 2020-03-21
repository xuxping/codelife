
#include <stdio.h>
#include <stdlib.h>
#include "../heap.c"

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

    freeHeap(h);
    return 0;
}
