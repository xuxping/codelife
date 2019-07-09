// 在数组中找第K小的数
// 对应 https://leetcode-cn.com/problems/kth-largest-element-in-an-array

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// 利用快速排序来做，快速排序在每次递归结束后都会有一个元素归位
int partition(int *arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j <= right - 1; ++j){
        if (arr[j] <= pivot){
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

/**
 * 时间复杂度为
 * T(n) = T(n/2) + O(n), 根据主定理：
 * T(n) = O(n)
 */
int findKNumberByQuickSort(int *arr, int arrSize, int k){
    if (arr == NULL || arrSize <= 0 || k <= 0 || k > arrSize){
        return -1;
    }
    int p = 0;
    int r = arrSize - 1;
    int kidx = k - 1; // 数组中索引
    while(p < r){
        int q = partition(arr, p, r);
        if (q == kidx){
            return arr[q];
        }else if(q < kidx){
            p = q + 1;
        }else{
            r = q - 1;
        }
    }
    return arr[p];
}

// 冒泡排序
// T(n) = O(nk)
int findKNumberByBubbleSort(int *arr, int arrSize, int k){
    if (arr == NULL || arrSize <= 0 || k <= 0 || k > arrSize){
        return -1;
    }

    for (int i = arrSize - 1; i >= arrSize - k; i--){
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr[arrSize - k];
}

/**
 * 利用堆结构, 这里采用的是最大堆，每次都是把最大的弹出来，因此找的是第K小的数
 * T(n) = O(nlogk)， 需要O(k)的空间
 */
int findKNumberByHeap(int *arr, int arrSize, int k){
    if (arr == NULL || arrSize <= 0 || k <= 0 || k > arrSize){
        return -1;
    }
    struct Heap *h = initHeap(k + 1);

    for (int i = 0; i < arrSize; ++i){
        push(h, arr[i]);
        if(h->size > k){
            pop(h);
        }
    }
    int n = pop(h);
    freeHeap(h);
    return n;
}


int main(void){
    const int arrSize = 1;
    int *arr = (int *)malloc(sizeof(int) * arrSize);
    if (arr == NULL)
    {
        printf("malloc faild, no memory!");
        exit(-1);
    }
    for (int i = 0; i < arrSize; ++i)
    {
        arr[i] = rand_idx(0, arrSize);
    }
    display(arr, arrSize);
    
    const int k = 1;
    int kNumber = findKNumberByQuickSort(arr, arrSize, k);
    printf("quicksort: the %d number is %d\n", k, kNumber);
    kNumber = findKNumberByBubbleSort(arr, arrSize, k);
    printf("bubble sort: the %d number is %d\n", k, kNumber);
    kNumber = findKNumberByHeap(arr, arrSize, k);
    printf("max heap: the %d number is %d\n", k, kNumber);

    display(arr, arrSize);
    free(arr);
}