/**
 * date: 2019-07-11
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
 * 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个
 * 重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出
 * 是第一个重复的数字2。
 */

#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

/**
 * 用数组下标来解决
 */
int findDuplicate(int *arr, int len)
{
    if (arr == NULL || len <= 0)
    {
        return -1;
    }

    // 检查数组 0 ~ n-1
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] < 0 || arr[i] > len - 1)
        {
            return -1;
        }
    }

    int temp = 0;
    for (int i = 0; i < len; ++i)
    {
        while (arr[i] != i)
        {
            if (arr[i] == arr[arr[i]])
            {
                return arr[i];
            }
            else
            {
                temp = arr[i];
                arr[i] = arr[temp];
                arr[temp] = temp;
            }
        }
    }
    return -1;
}

int main(void)
{
    const int len = 10;
    int arr[10] = {0, 2, 3, 4, 2, 3, 5, 6, 7, 9};
    display(arr, len);
    int res = findDuplicate(arr, len);
    printf("res = %d\n", res);
    return 0;
}