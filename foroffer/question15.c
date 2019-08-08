// 统计一个数中，二进制中1的个数

#include <stdio.h>

/**
 * 之前的错误方法，没有考虑到负数左移时会出现死循环
 * 比如-1>>1 = 1, 但是
 * -1/2 = 0
 */
int preNumberOfOne(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1 ;
        printf("%d \n", n);
    }
    return count;
}

int numberOfOne1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int numberOfOne2(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}

/**
 * 扩展题目，输入两个数m和n,计算需要改变m的二进制表示中的多少位才能得到n
 * 解法：第一步求这两个数的异或，第二步统计异或结果中的1的位数
 */
int numberofChangeFromMtoN(int m, int n)
{
    int k = m ^ n;
    return numberOfOne2(k);
}

int main(void)
{
    // int count1 = numberOfOne1(10);
    // int count2 = numberOfOne2(10);

    // printf("count1: %d\n", count1);
    // printf("count2: %d\n", count2);

    // printf("m->n, change number: %d\n", numberofChangeFromMtoN(10, 13));

    int count1 = preNumberOfOne(-101);
    printf("count1: %d\n", count1);

    return 0;
}