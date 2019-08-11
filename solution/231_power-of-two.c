// 2的幂
// https://leetcode-cn.com/problems/power-of-two/

#include <stdio.h>

/**
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 思路： 2 的幂次方的二进制表示中只有一个1
 * T(n) = O(n)
 */
int isPowOfTwo(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        // cnt += (n % 2);
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt == 1;
}

/**
 * 如果一个数是 2 的次方数的话，那么它的二进数必然是最高位为1，
 * 其它都为 0 ，那么如果此时我们减 1 的话，则最高位会降一位，
 * 其余为 0 的位现在都为变为 1，那么我们把两数相与，就会得到 0。
 * T(n) = O(1)
 */
int isPowOfTwo2(int n)
{
    return (n > 0) && (!(n & (n - 1)));
}

/**
 * 求2的n次幂
 */
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    double half = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else if (n > 0)
    {
        return half * half * x;
    }
    else
    {
        return half * half / x;
    }
}

int main(void)
{
    // int n = isPowOfTwo2(128);
    int n = myPow(-2,-3);
    printf("n == %d", n);
    return 0;
}
