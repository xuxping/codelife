// 快速排序, 分而治之

#include <stdio.h>
#include <stdlib.h>
#include "utils.c"


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 《算法导论》7.1节的版本
 * T(n) = O(n*lgn)
 */
int partition(int *arr, int p, int r)
{
    // 将最后一个元素作为pivot
    int pivot = arr[r];
    int i = p - 1;
    int temp = 0;

    // from p to r-1
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

/**
 * 随机挑选一个元素作为pivot
 */
int random_partition(int *arr, int p, int r)
{
    // 将最后一个元素作为pivot
    int idx = rand_idx(p, r);
    swap(&arr[r], &arr[idx]);
    
    int j = partition(arr, p, r);

    return j;
}

void quicksort2(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort2(arr, p, q - 1);
        quicksort2(arr, q + 1, r);
    }
}

void quicksort3(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = random_partition(arr, p, r);
        quicksort3(arr, p, q - 1);
        quicksort3(arr, q + 1, r);
    }
}

/**
 * 易于理解一点，左右同时扫描
 * T(n) = O(n*lgn)
 */
void quicksort1(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r;
    int pivot = arr[l];
    int temp = 0;
    while (i != j)
    {
        while (arr[j] >= pivot && i < j)
        {
            j--;
        }
        while (arr[i] <= pivot && i < j)
        {
            i++;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    arr[l] = arr[i];
    arr[i] = pivot;
    // display(arr, 10);
    quicksort1(arr, l, i - 1);
    quicksort1(arr, i + 1, r);
}



int main(void)
{
    const int arrSize = 100000;

    int *arr = (int *)malloc(sizeof(int) * arrSize);
    if (arr == NULL)
    {
        printf("malloc faild, no memory!");
        exit(-1);
    }
    for (int i = 0; i < arrSize; ++i)
    {
        arr[i] = rand_idx(0, arrSize);
        // printf("i=%d ", arr[i]);
    }
    // printf("\n");

    unsigned long start_time = gettime();
    // quicksort1(arr, 0, arrSize - 1);
    // quicksort2(arr, 0, arrSize - 1);
    quicksort3(arr, 0, arrSize - 1);
    unsigned long end_time = gettime();

    printf("cost %lu ms\n", (end_time - start_time));
    // display(arr, arrSize);

    free(arr);
}
