// 在数组中找第K小的数

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
int findKNumberByQuickSort(int *arr, int p, int r, int k){
    int kidx = k - 1; // 数组中索引
    int size = r + 1;
    if (p < r){
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
        if (p == kidx){
            return arr[p];
        }
    }
    // 没找到
    return -1;
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
    const int arrSize = 10;
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
    
    const int k = 9;
    int kNumber = findKNumberByQuickSort(arr, 0, arrSize - 1, k);
    printf("quicksort: the %d number is %d\n", k, kNumber);
    kNumber = findKNumberByBubbleSort(arr, arrSize, k);
    printf("bubble sort: the %d number is %d\n", k, kNumber);
    kNumber = findKNumberByHeap(arr, arrSize, k);
    printf("max heap: the %d number is %d\n", k, kNumber);

    display(arr, arrSize);
    free(arr);
}