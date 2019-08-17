/**
 * 最小编辑距离：求一个序列经过最少次变换(增删改)后，转化成另一个序列。应用如下：
 *  1、单词拼写纠错，比如本项目就把algorithms 拼成了algorthms
 *  2、两块基因序列的不一致检查  
 *  3、语音识别中的字错误率计算
 *  4、求两个句子之间的相似度
 *  ...
 * 
 * 示例：
 *  X: abode, Y: blog
 * 需要操作4次：
 * 1. delete a -> bode
 * 2. insert l after b -> blode
 * 3. delete d -> bloe
 * 4. substitute e with g -> 
 * 
 * 本题最难的地方就是数组的下标 (>·<)
 */ 

#include <stdio.h>
#include <string.h>

/**
 * 第一步：定义最优值的解空间
 *  For 1 ≤ i ≤ m, and 1 ≤ j ≤ n,
 *  Define d[i,j] to be the minimum edit distance of the substrings X[1..i] and Y [1..j].
 * 
 * 第二步：递归定义最优解的值
 *  To turn X[1..i] into Y[1..j], we have three cases:
 *  Case 1: Turn X[1..i-1] into Y[1..j] and delete X[i]
 *         Example 1: MED (cxy -> dab) = MED (cx -> dab) + 1
 *  Case 2: Turn X[1..i] into Y[1..j-1] and insert Y[j]
 *         Example 2: MED (cxy -> dab) = MED (cxy -> da) + 1
 *  Case 3: Turn X[1..i-1] into Y[1..j-1] and substitute X[i] with Y[j] if needed (X[i] ≠ Y[j])
 *         Example 3.1: MED (cxy -> dab) = MED (cx -> da) + 1
 *         Example 3.2: MED (cxy -> day) = MED (cx -> da)
 *  因此DP方程为：
 *                 {  DP[i - 1, j] + 1 , delete
 *  DP[i, j] = min {  DP[i, j - 1] + 1 , insert
 *                 {                  { 0, if X[i] == Y[j], substitute
 *                 {  DP[i-1, j-1] +  { 1, if X[i] != Y[j], substitute
 * 
 *  history[i, j] = left: insert, 
 *                  up: delete, 
 *                  left up: substitute
 */
int editDistance(char *X, char *Y){
    int lenX = strlen(X); // strlen会忽略\0
    int lenY = strlen(Y);

    int DP[lenX + 1][lenY + 1];
    int history[lenX + 1][lenY + 1];

    int i = 0, j = 0;

    /**
     *  初始表
     */ 
    for(i = 0; i <= lenX; ++i){
        DP[i][0] = i;
        history[i][0] = 0;  // UP
    }
    for (j = 0; j <= lenY; ++j){
        DP[0][j] = j;
        history[0][j] = 1;  // LEFT
    }
    history[0][0] = -1;

    for(i = 1; i <= lenX; ++i){
        for (j = 1; j <= lenY; ++j){
            int c = 0;
            // 注意字符串数组的索引
            if (X[i - 1] != Y[j - 1]){
                c = 1;
            }
            int leftUpVal = DP[i - 1][j - 1] + c;
            int leftVal = DP[i][j - 1] + 1;
            int UpVal = DP[i - 1][j] + 1;

            if ((leftUpVal <=  UpVal) && (leftUpVal <= leftVal)){
                DP[i][j] = leftUpVal;
                history[i][j] = 2;  // left up
            }else if((leftVal < UpVal) && (leftVal < leftUpVal)){
                DP[i][j] = leftVal;
                history[i][j] = 1;  // LEFT
            }else{
                DP[i][j] = UpVal;
                history[i][j] = 0;  // UP
            }
        }
    }

    i = lenX;
    j = lenY;

    // 回溯
    while(i >= 0 && j >= 0){
        if (history[i][j] == 2){
            if(X[i-1] != Y[j-1]){
                printf("Substitute %c to %c\n", X[i-1], Y[j-1]);
            }else{
                printf("do nothing\n");
            }
            i--;
            j--;
        }else if(history[i][j] == 0){
            printf("delete %c \n",X[i-1]);
            i--;
        }else if(history[i][j] == 1){
            printf("insert %c\n",Y[j-1]);
            j--;
        }else{
            break;
        }
    }

    // 打印DP数组
    for(i = 0; i <= lenX; ++i){
        for(j = 0; j <= lenY; ++j){
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
    
    // 打印history数组
    for(i = 0; i <= lenX; ++i){
        for(j = 0; j <= lenY; ++j){
            if (history[i][j] == 0){
                printf("U ");
            }
            if (history[i][j] == 1){
                printf("L ");
            }
            if (history[i][j] == 2){
                printf("LU ");
            }
            if (history[i][j] == -1){
                printf("X ");
            }
        }
        printf("\n");
    }

    return DP[lenX][lenY];
}



int main(void){
    // char *X = "algorthms";
    // char *X = "ABCBDAB";
    char *X = "";
    // char *Y = "algorithms";
    char *Y = "BDCABA";
    int distance = editDistance(X, Y);

    printf("min edit distance: %d\n", distance);
    return 0;
}