// 最长公共子序列问题

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 最长公共子序列问题
 * if xi = yi: dp[i, j] = dp[i-1, j-1] + 1
 * else dp[i,j] = max{dp[i-1, j], d[[i, j-1]]}
 */ 
void longestCommonSubsequence(char *X, char *Y){
    if(X == NULL || Y == NULL || *X == '\0' || *Y =='\0') return;

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];  // 存储最长序列的长度
    int path[m + 1][n + 1];  // 用于回溯
    int i = 0;
    int j = 0;
    // 初始化
    for(i = 0; i <= m; ++i){
        dp[i][0] = 0;
    }
    for(j = 0; j <= n; ++j){
        dp[0][j] = 0;
    }

    for(i = 1; i <= m; ++i){
        for(j = 1; j <= n; ++j){
            if(X[i - 1] == Y[j - 1]){
            // if(X[i] == Y[j]){
                dp[i][j] =  dp[i - 1][j - 1] + 1;
                path[i][j] = 0; // 'LU'
            }else if(dp[i - 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 1;  // 'U'
            }else{
                dp[i][j] = dp[i][j - 1];
                path[i][j] = 2;  // 'L'
            }
        }
    }

    // 回溯打印字符串
    while(i != 0 && j != 0){
        if (path[i][j] == 0){
            printf("%c", X[i-1]);
            i--;
            j--;
        }else if(path[i][j] == 1){
            i--;
        }else{
            j--;
        }
    }
}

/**
 * 最长公共连续子序列问题   
 * if xi = yi: dp[i, j] = dp[i-1, j-1] + 1
 * else: dp[i, j] = 0
 */ 
void longestCommonString(char *X, char *Y){
    if(X == NULL || Y == NULL || *X == '\0' || *Y =='\0') return;

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];  // 存储最长序列的长度
    int lmax= 0, pmax = 0;  // 用于回溯
    int i = 0;
    int j = 0;
    // 初始化
    for(i = 0; i <= m; ++i){
        dp[i][0] = 0;
    }
    for(j = 0; j <= n; ++j){
        dp[0][j] = 0;
    }

    for(i = 1; i <= m; ++i){
        for(j = 1; j <= n; ++j){
            if(X[i - 1] == Y[j - 1]){
                dp[i][j] =  dp[i - 1][j - 1] + 1;
                if (dp[i][j] > lmax){
                    lmax = dp[i][j];
                    pmax = i;
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }

    // 回溯打印字符串
    if(lmax != 0){
        for(i = pmax-lmax +1; i <= pmax; i++){
            printf("%c", X[i - 1]);
        }
    }
}

int main(void){
    char *X = "ABCBDAB";
    char *Y = "BDCABA";
    // BCBA
    longestCommonSubsequence(X, Y);
    printf("\n");
    longestCommonString(X, Y);
    return 0;
}