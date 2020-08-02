// 求解八皇后问题，有一个 8x8 的棋盘，希望往里放 8 个棋子（皇后），
// 每个棋子所在的行、列、对角线都不能有另一个棋子。

// 解法：
// 把这个问题划分成 8 个阶段，依次将 8 个棋子放到第一行、
// 第二行、第三行……第八行。在放置的过程中，我们不停地检查当前放法，
// 是否满足要求。如果满足，则跳到下一行继续放置棋子；如果不满足，那就再换一种放法，继续尝试。

#include <stdio.h>

//判断row行column列放置是否合适
int isOk(int *result, int row, int column){
    int leftup = column - 1, rightup = column + 1;
    for (int i = row - 1; i >= 0; --i) { // 逐行往上考察每一行 
        if (result[i] == column) return 0; // 第i行的column列有棋子吗？ 

        if (leftup >= 0) { // 考察左上对角线：第i行leftup列有棋子吗？ 
        if (result[i] == leftup) return 0; 
        } if (rightup < 8) { // 考察右上对角线：第i行rightup列有棋子吗？ 
        if (result[i] == rightup) return 0; 
        } 
        --leftup; 
        ++rightup; 
    } 
    return 1;
}

void display(int *result){
    for (int row = 0; row < 8; ++row) { 
        for (int column = 0; column < 8; ++column) { 
            if (result[row] == column) printf("Q "); 
            else printf("* "); 
        } 
        printf("\n");
    }
    printf("\n");
}

void cal8queue(int *result, int row){
    if (row == 8){
        display(result);
        return; // 8行棋子都放好了，已经没法再往下递归了，所以就return
    }

    for(int column = 0; column < 8; ++column){ // // 每一行都有8中放法
        if(isOk(result, row, column) == 1){
            result[row] = column; // 第row行的棋子放到了column列
            cal8queue(result, row + 1); // 考察下一行
        }
    }
}


int main(void){
    int result[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    cal8queue(result, 0);
}