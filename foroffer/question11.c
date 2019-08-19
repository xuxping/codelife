// 求旋转数组中的最小数字
// input: [3,4,5,1,2]
// output: 1


#include <stdio.h>

/**
 * 顺序查找最小值
 */
int minInOrder(int *arr, int l, int r){
    int pivot = arr[l];
    for (int i = l; i < r; ++i){
        if (arr[i] < pivot){
            pivot = arr[i];
        }
    }
    return pivot;
}

/**
 * 考虑的点:
 * 1. 左边第一个数字一定比最右边的数字大
 * 2. 数组中存在重复的数字, 如[3,4,5,1,1,1,2]
 */
int g_kInputInvalid = 0;
int findLowestValue(int *arr, int arrSize){
    if (arr == NULL || arrSize <= 0){
        g_kInputInvalid = 1;
        return 0;
    }

    int start = 0, end = arrSize - 1;
    int mid = start;
    while(arr[start] >= arr[end]){
        // 右边大于左边
        if((end - start) == 1){
            mid = end;
            break;
        }

        mid = (start + end) / 2;
        // 如果下标start，end和mid相等，则只能进行顺序查找
        if(arr[start] == arr[end] && arr[start] == arr[mid]){
            return minInOrder(arr, start, end);
        }

        if(arr[mid] >= arr[start]){
            start = mid;
        }else if(arr[mid] <= arr[end]){
            end = mid;
        }
    }
    g_kInputInvalid = 0;
    return arr[mid];
}

int main(void){
    int arr[6] = {3, 4, 5, 0, 1, 2};
    int lowValue = findLowestValue(arr, 6);
    if (g_kInputInvalid == 1){
        printf("invalid input!\n");
    }else{
        printf("lowValue: %d\n", lowValue);
    }
    return 0;
}