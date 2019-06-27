// 冒泡排序
#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

/**
 * T(n) = O(n^2)
 */
void bubble_sort(int *arr, int arrSize)
{
    // 标志是否有交换
    int isChange = 0;
    int temp = 0;
    // i from arrSize - 1 to 0
    for (int i = arrSize - 1; i >= 0; i--)
    {
        isChange = 0;
        // j from 0 to i
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChange = 1;
            }
        }
        // display(arr, arrSize);
        // 提前停止
        if (!isChange)
        {
            printf("no exchange,i=%d\n", arrSize - i);
            break;
        }
    }
}

int main(void)
{
    const int arrSize = 100;

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
    printf("before sort\n");
    display(arr, arrSize);

    unsigned long start_time = gettime();
    // quicksort1(arr, 0, arrSize - 1);
    bubble_sort(arr, arrSize);
    unsigned long end_time = gettime();

    printf("cost %lu ms\n", (end_time - start_time));
    printf("after sort\n");
    display(arr, arrSize);

    free(arr);
}
