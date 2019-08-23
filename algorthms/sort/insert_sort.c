
// 插入排序
#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

/**
 * T(n) = O(n^2)
 */
void insert_sort(int *arr, int arrSize)
{
    if(arr == NULL || arrSize <= 1) return;

    for (int i = 1; i < arrSize; ++i){
        int value = arr[i];
        // 有序区
        int j = i - 1;
        for (; j >= 0 ; --j){
            if ( arr[j] > value){
                arr[j + 1] = arr[j];
            }else{
                break;
            }
        }
        arr[j + 1] = value;
    }
}

int main(void)
{
    const int arrSize = 10;
    int *arr = createRandomArr(arrSize);

    printf("before sort\n");
    display(arr, arrSize);

    unsigned long start_time = gettime();
    // quicksort1(arr, 0, arrSize - 1);
    insert_sort(arr, arrSize);
    unsigned long end_time = gettime();

    printf("cost %lu ms\n", (end_time - start_time));
    printf("after sort\n");
    display(arr, arrSize);

    free(arr);
}
