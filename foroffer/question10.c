/**
 * fabonacci, 典型的递归问题
 */ 
#include <stdio.h>

/**
 * D&C： 教科书解法，一旦n较大，存在较多的重复计算，造成严重的性能问题， 
 * 并且造成栈溢出
 */
long long fabonacciRecursive(unsigned int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return fabonacciRecursive(n - 1) + fabonacciRecursive(n - 2);
}


// 循环解法
long long fabonacci(unsigned int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long firstNum = 1;
    long long secondNum = 0;
    long long total = 0;
    for (int i = 2; i <= n; ++i){
        total = firstNum + secondNum;
        secondNum = firstNum;
        firstNum = total;
    }
    return total;
}


// 动态规划法 DP[i] = DP[i-1]+DP[i-2]
// 防止重复进行计算
long long fabonacciDP(unsigned int n){
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}


/**
 * 青蛙跳台阶问题，与fabonacci只是初始部分存在一点不一样
 * 循环解法和DP解法可以参考fabonacci
 */ 
long long jump(unsigned int n){
    if (n <= 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    // n > 2
    return jump(n - 1) + jump(n - 2);
}


int main(void){
    const int n = 2;
    long long res1 = fabonacciRecursive(n);
    printf("res1 = %lld \n", res1);

    long long res2 = fabonacci(n);
    printf("res2 = %lld \n", res2);

    long long res3 = fabonacciDP(n);
    printf("res3 = %lld \n", res3);

    long long jump1 = jump(n);
    printf("jump1 = %lld \n", jump1);
    
    return 0;
}