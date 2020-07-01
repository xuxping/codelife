
// 二进制表达式中数字位数为 ‘1’ 的个数
// https://leetcode-cn.com/problems/number-of-1-bits/

#include <stdio.h>

int hammingWeight(int n) {
    int count = 0;

    while(n != 0){
        count++;
        n &= (n - 1);
    }

    return count;
}

int main(int argc, char const *argv[])
{
    printf("3=>%d\n",hammingWeight(3));
    printf("15=>%d",hammingWeight(15));
    return 0;
}
