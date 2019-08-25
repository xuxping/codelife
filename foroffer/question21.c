// 调整数组，使得数组中所有奇数位于偶数前面
// 考虑程序的可扩展性

#include <stdio.h>
#include <stdlib.h>
#include "../algorthms/utils.c"

int isEnvent(int n){
    return (n & 1) == 0;
}

// 在C中如何将函数作为参数进行传递
void reOrder(int *arr, int len, int (*func)(int)){
    if (arr == NULL || len <= 0) return;

    int low = 0;
    int high = len - 1;

    while (low < high){
        while(low < high && !func(arr[low])){
            low++;
        }
         while(low < high && func(arr[high])){
            high--;
        }

        if(low < high){
            swap(&arr[low], &arr[high]);
        }
    }
}

void testIsEnvent(){
    const int len = 10;
    int *arr = createRandomArr(len);
    display(arr, len);
    reOrder(arr, len, isEnvent);
    display(arr, len);
}


int main(void){
    testIsEnvent();
    return 0;
}
