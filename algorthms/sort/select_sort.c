// 选择排序
#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"


// 选择排序算法的实现思路有点类似插入排序，也分已排序区间和未排序区间。
// 但是选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。

void select_sort(int *arr, int arrSize){
    for (int i = 0; i < arrSize - 1; ++i){
        int j = i + 1;
        int min = arr[j];
        int min_i = j;
        // 会从未排序区间中找到最小的元素, 0-i是已拍好像的区域
        for (; j < arrSize; ++j){
            if (arr[j] < min){
                min = arr[j];
                min_i = j;
            }
        }
        if(min_i == i) continue;
        swap(&arr[min_i], &arr[i]);
    }
}

int main(void)
{
    const int arrSize = 15;
    int *arr = createRandomArr(arrSize);

    printf("before sort\n");
    display(arr, arrSize);

    unsigned long start_time = gettime();
    // quicksort1(arr, 0, arrSize - 1);
    select_sort(arr, arrSize);
    unsigned long end_time = gettime();

    printf("cost %lu ms\n", (end_time - start_time));
    printf("after sort\n");
    display(arr, arrSize);

    free(arr);
}
