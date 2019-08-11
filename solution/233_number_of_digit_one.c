// 求1~n之间的数总共有多少个1
// https://leetcode-cn.com/problems/number-of-digit-one/solution
/**
 * 比如0-10，有[1,10], 总共有两个1
 * 0-40，，有[1,10,11,....,21,31],有14个1
 */

#include <stdio.h>

/**
 * 暴力方法，容易超时
 * T(n) = O(n*log_10(n))
 */
int count_k_times(int number)
{
    if (number < 1 || number > 2147483647)
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i <= number; ++i)
    {
        int j = i;
        while (j > 0)
        {
            if (j % 10 == 1)
            {
                count++;
            }

            j = j / 10;
        }
    }
    return count;
}

/**
 * https://leetcode-cn.com/problems/number-of-digit-one/solution/shu-zi-1-de-ge-shu-by-leetcode/
 */
int count_k_times2(int number)
{
    if (number < 1 || number > 2147483647)
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i <= number; i *= 10)
    {
        int divider = i * 10;
        int t = number % divider - i + 1;
        t = t > 0LL ? t : 0LL;
        t = t < i ? t : i;
        // count += (number / divider) * i + min(max(number % divider - i + 1, 0LL), i);
        count += (number / divider) * i + t;
    }
    return count;
}

int main(void)
{
    int number = 40;
    // int num = count_one(number);
    int num = count_k_times2(number);
    printf("number of 1: %d\n", num);
}
