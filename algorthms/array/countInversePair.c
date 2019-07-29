// 统计数组中有多少个逆序对

#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

/**
 * 合并两个有序数组
 */
int countInversePairCore(int *arr, int l, int mid, int r)
{
    int temp[r - l + 1];
    int i = l;
    int j = mid + 1;
    int k = 0;
    int inversePairNum = 0;
    while (i <= mid && j <= r){
        if (arr[i] > arr[j]){
            // if ai > bj, 则bj小于a[i..mid]之间所有元素
            inversePairNum += mid - i + 1;
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= r){
        temp[k++] = arr[j++];
    }
    for(int n = 0; n < r - l + 1; ++n){
        arr[l + n] = temp[n];
    }
    return inversePairNum;
}

/**
 * 暴力的方法T(n) = O(n)
 * 
 * 利用归并排序来做，归并排序在交换两个元素的顺序时可以进行逆序统计
 * T(n) = 2*T(n/2) + O(n)
 */
int countInversePair(int *arr, int l, int r)
{
    if (arr == NULL) return 0;
    if(l == r){
        return 0;
    }
    int mid = (l + r) >> 1;
    int n1 = countInversePair(arr, l, mid);
    int n2 = countInversePair(arr, mid + 1, r);
    int n3 = countInversePairCore(arr, l, mid, r);
    return n1 + n2 + n3;
}

int main(void)
{
    const int arrLen = 12;
    int arr[arrLen] = {14, 7, 18, 3, 10,19,11,23, 2, 25,16,17};
    display(arr, arrLen);
    int result = countInversePair(arr, 0, arrLen-1);
    printf("result = %d\n", result);
    display(arr, arrLen);
    return 0;
}

