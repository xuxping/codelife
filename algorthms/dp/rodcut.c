// 钢条切割问题
// 参考算法课
// 给定一个长度为l的钢条，和一个长度价目表p，要求如何切割钢条，使得卖出的总价最大

#include <stdio.h>


/**
 * 递归解法
 * rn = max{pn, r_1 + r_(n-1) , r_2 + r_(n-2), r_(n-1) + r_1}
 * @param rodLength: 钢条长度
 * @param priceTable(array): 价目表
 */ 
int rodcutByRecursive(const int rodLength, const int *priceTable){
    if(rodLength <= 0 || priceTable == NULL) return 0;

    int rn = 0;

    for (int i = 1; i <= rodLength; ++i){
        // i-1，数组下标从0开始
        int profile = priceTable[i - 1] + rodcutByRecursive(rodLength - i, priceTable);
        rn = profile > rn ? profile: rn;
    }
    return rn;
}


/**
 * 动态规划解法
 * rn = max{pi + r_(j-i)}, s.t: 1 <= j <= n, i <= j
 * @param rodLength: 钢条长度
 * @param priceTable(array): 价目表
 */ 
int rodcutByDP(const int rodLength, const int *priceTable){
    if(rodLength <= 0 || priceTable == NULL) return 0;

    int dp[rodLength + 1];
    int history[rodLength + 1];  // 用于回溯
    dp[0] = 0;
    for(int j = 1; j <= rodLength; ++j){
        int rn = -1;
        for (int i = 1; i <= j; ++i){
            int profile = priceTable[i - 1] + dp[j - i];
            if(profile > rn){
                rn = profile;
                history[j] = i;
            }
        }
        dp[j] = rn;
    }
    
    int n = rodLength;

    // 回溯
    while (n > 0){
        printf("%d ", history[n]);
        n = n - history[n];
    }
    printf("\n");

    return dp[rodLength];
}


int main(void){
    const int len = 10;
    const int priceTable[len] = {1, 5 ,8, 9, 10, 17, 17, 20, 24, 26};
    int profile = rodcutByRecursive(len, priceTable);
    printf("DC: profile: %d\n", profile);

    profile = rodcutByDP(len, priceTable);
    printf("DP: profile: %d\n", profile);

    return 0;
}