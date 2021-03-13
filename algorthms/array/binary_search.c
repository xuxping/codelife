/**
 *  二分查找：
 * 
 * 扩展(数组可能有重复)
 * 1. 查找第一个值等于给定值的元素  
 * 2. 查找最后一个值等于给定值的元素
 * 3. 查找第一个大于等于给定值的元素
 * 4. 查找最后一个小于等于给定值的元素
 * 参考：
 * https://time.geekbang.org/column/article/42520
 * https://time.geekbang.org/column/article/42733
 */ 

#include <stdio.h>

/**
 * 二分查找，每次比较将区间范围缩小一半，时间复杂度为O(logn)
 * 1. 二分查找针对的是有序数组
 * 2. 数组太小，与顺序查找没多大的性能优势  
 * 3. 数组太大，如果不是内存地址不是连续的也无法使用    
 * 假设数组中不存在重复的数，并且数据从小到大有序
 */ 
int bsearch(int *arr, int len, int value){
    if (arr == NULL || len <= 0) return -1;

    int low  = 0;
    int high = len - 1;
    // 1. 注意循环退出条件是 <= 而不是 <。 这个需要看写法
    while(low <= high){
        // 2. low + high可能会造成整数溢出
        // int mid = (low + high) / 2;
        int mid = low + ((high - low) >> 1);

        if (arr[mid] == value ){
            return mid;
        }

        // 3. low 和 high的更新
        if (arr[mid] < value){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}


// 1. 查找第一个值等于给定值的元素 
int bsearch1(int *arr, int len, int value){
    if (arr == NULL || len <= 0) return -1;

    int low  = 0;
    int high = len - 1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if (arr[mid] < value){
            low = mid + 1;
        }else if(arr[mid] > value){
            high = mid - 1;
        }else{
            // 判断是否是第一数
            if((mid == 0) || arr[mid - 1] != value){
                return mid;
            }else{
                high = mid - 1;
            }
        }
    }

    return -1;
}

// 2. 查找最后一个值等于给定值的元素
int bsearch2(int *arr, int len, int value){
    if (arr == NULL || len <= 0) return -1;

    int low  = 0;
    int high = len - 1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if (arr[mid] < value){
            low = mid + 1;
        }else if(arr[mid] > value){
            high = mid - 1;
        }else{
            // 判断是否是第一数
            if((mid == len - 1) || arr[mid + 1] != value){
                return mid;
            }else{
                low = mid + 1;
            }
        }
    }

    return -1;
}

// 3. 查找第一个大于等于给定值的元素
int bsearch3(int *arr, int len, int value){
    if (arr == NULL || len <= 0) return -1;

    int low  = 0;
    int high = len - 1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);

        if(arr[mid] >= value){
            if (mid == 0 || arr[mid - 1] < value){
                return mid;
            }
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}


// 4. 查找最后一个小于等于给定值的元素
int bsearch4(int *arr, int len, int value){
    if (arr == NULL || len <= 0) return -1;

    int low  = 0;
    int high = len - 1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if(arr[mid] <= value){
            if(mid == len - 1 || arr[mid + 1] > value){
                return mid;
            }
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(void){
    const int len = 6;
    int arr[len] = {3,5,6,8,9,10};
    int value = 7;

    int idx = bsearch(arr, len, value);
    printf("idx = %d\n", idx);

    idx = bsearch1(arr, len, value);
    printf("idx = %d\n", idx);
    idx = bsearch2(arr, len, value);
    printf("idx = %d\n", idx);
    idx = bsearch3(arr, len, value);
    printf("idx = %d\n", idx);
    idx = bsearch4(arr, len, value);
    printf("idx = %d\n", idx);

    return 0;
}