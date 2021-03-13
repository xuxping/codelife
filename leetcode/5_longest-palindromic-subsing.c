// 最长回文子串
// https://leetcode-cn.com/problems/longest-palindromic-subsing/

/**
Input:ababacaa
Output:
      algorithms1: ababa
      algorithms2: ababa

Input:adbasdcd
Output:
      algorithms1: dcd
      algorithms2: dcd
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 获取字符串长度
 */
int getstrlen(char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    char *p = s;
    int len = 0;
    while (*p++ != '\0')
    {
        len += 1;
    }
    return len;
}

void display(int **dp, const int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d\t", *(dp[i] + j));
        }
        printf("\n");
    }
}

/**
 * 动态规划方法：
 * 1、刻画最优解的结构特征
 * 2、递归定义最优解的值，将最优解与子问题联系起来（注意边界）
 * dp[i, j] = dp[i+1, j-1], if s[i] == s[j]
 * 3、从小到上求解
 * 
 * T(n) = O(n^2/2) = O(n^2)
 * 如果字符串长度太长，则二维数组较大，有很多浪费的空间，可以进一步优化
 * 
 * 本函数采用动态数组分配，不适合提交
 */
char *longestPalindrome1(char *s)
{
    if (s == NULL)
        return NULL;
    const int len = strlen(s);

    // int dp[len][len];
    // 使用二维指针便于传递二维数组
    int **dp = (int **)malloc(sizeof(int *) * len);
    for (int i = 0; i < len; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * len);
    }

    int longest = 1;
    int start = 0, end = 0;
    // 初始化一字母和二字母的回文
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dp[i][j] = 0;
            if (i == j)
            {
                dp[i][j] = 1;
            }
        }
        // 二字母的回文
        if (s[i] == s[i + 1] && i + 1 < len)
        {
            dp[i][i + 1] = 1;
            longest = 2;
            start = i;
            end = i + 1;
        }
    }

    // display(dp, len);
    // j from 1 to len
    for (int j = 1; j < len; j++)
    {
        // i from 0 to j, 只使用一半数组即可
        for (int i = 0; i < j; i++)
        {
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                // 保存最长的结构索引
                if (j - i + 1 > longest)
                {
                    longest = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }

    // char ret[end - start + 1];
    char *ret = (char *)malloc(sizeof(char) * (end - start + 1));

    int idx = 0;
    for (int k = start; k <= end; k++)
    {
        ret[idx++] = s[k];
    }
    display(dp, len);
    for (int i = 0; i < len; i++){
        free(dp[i]);
    }
    free(dp);
    return ret;
}




/**
 * 中心扩散法
 */
int expandCenter(char *s, const int len, const int left ,const int right){
    int L = left;
    int R = right;

    while(L >= 0 && R < len && s[L] == s[R]){
        L--;
        R++;
    }

    return R - (L + 1);
}

/**
 * 中心扩散法:
 * 原理：回文中心的两侧互为镜像
 */
char *longestPalindrome2(char *s)
{
    if (s == NULL)
        return NULL;

    const int len = strlen(s);

    int longest = 1;
    int start = 0, end = 0;
    int l1 = 0, l2 = 0, max = 0;
    for (int i = 0; i < len; i++)
    {
        l1 = expandCenter(s, len, i, i);
        l2 = expandCenter(s, len, i, i + 1);
        max = l1 > l2 ? l1 :l2;
        if(max > end - start){
            start = i - (max - 1) / 2;
            end = i + max / 2;
        }
    }
    // char ret[end - start + 1];
    char *ret = (char *)malloc(sizeof(char) * (end - start + 1));

    int idx = 0;
    for (int k = start; k <= end; k++)
    {
        ret[idx++] = s[k];
    }
    return ret;
}


int main(void)
{
    char *s = "adbasdcd";

    char *s1 = longestPalindrome1(s);
    printf("algorithms1: %s\n", s1);
    
    s1 = longestPalindrome2(s);
    printf("algorithms2: %s\n", s1);

}