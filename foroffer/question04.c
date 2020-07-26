// 二维数组中的查找
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <stdio.h>
#define bool int
#define false 0
#define true 1

/**
 * 从右上角开始开始遍历
 **/
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){

    if(matrixSize == 0||*matrixColSize==0)
         return false;

    int n = 0;
    int m = *matrixColSize - 1;

    while(n < matrixSize && m >= 0){
        if(matrix[n][m] == target){
            return true;
        }

        if (matrix[n][m] > target){
            m--;
        }else{
            n++;
        }
    }
    return false;
}