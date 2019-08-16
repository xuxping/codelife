// 动态规划：减绳子

#include <stdio.h>

int maxCutProduct(int length){

    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;
    if (length == 4) return 4;

    int product[length + 1];

    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;

    int max = 0;

    for(int j = 4; j <= length; ++j){
        max = 0;
        for (int i = 1; i < j; ++i){
            int value = product[i] * product[j - i];
            if (max < value){
                max = value;
            }
        }
        product[j] = max;
    }

    return max;
}

int main(void){
    int max = maxCutProduct(8);
    printf("max: %d\n", max);
    return 0;
}