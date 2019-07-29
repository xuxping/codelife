#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

/**
 * 给定两个数组，进行合并
 */
void mergeArr1(int *A, int lengthOfA, int *B, int lengthOfB){
    const int sizeOfC = lengthOfA + lengthOfB;
    int *C = (int *)malloc(sizeof(int) * sizeOfC);
    
    int k = 0;
    int i = 0, j = 0;
    while(i < lengthOfA && j < lengthOfB){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = B[j++];
        }
    }

    while(i < lengthOfA){
        C[k++] = A[i++];
    }

    while(j < lengthOfB){
        C[k++] = B[j++];
    }
    display(C, sizeOfC);

    free(C);
}

/**
 * 《剑指offer》第5题；扩展题
 * 合并两个排序数组A1和A2，内存在A1的末尾有足够的空余空间能够容纳A2，
 * 实现一个算法将A2插入A1，并保证有序，假设A1和A2中的数都不为0
 */
void mergeArr2(int *A1, int sizeOfA1, int *A2, int lenOfA2){
    if(A1 == NULL || A2 == NULL || sizeOfA1 <=0 || lenOfA2 <= 0){
        return;
    }
    int lenOfA1 = 0;
    int i = 0;
    // 求数组长度
    while(A1[i] != 0){
        ++lenOfA1;
        ++i;
    }

    // A1的内存不够
    if ((lenOfA1 + lenOfA2) > sizeOfA1) return;

    int idxOfNew = lenOfA1 + lenOfA2 - 1;
    int idxOfA1 = lenOfA1 - 1; 
    int idxOfA2 = lenOfA2 - 1;

    while(idxOfA1 >= 0 && idxOfA2 >= 0)
    {
        if (A1[idxOfA1] > A2[idxOfA2]){
            A1[idxOfNew--] = A1[idxOfA1--];
        }else{
            A1[idxOfNew--] = A2[idxOfA2--];
        }
    }
    while(idxOfA1 >= 0){
        A1[idxOfNew--] = A1[idxOfA1--];
    }

    while(idxOfA2 >= 0){
        A1[idxOfNew--] = A2[idxOfA2--];
    }
}

void testMergeArr1(){
    int A[3] = {1,3,5};
    int B[4] = {2,4,6, 7};
    mergeArr1(A, 3, B, 4);

}

void testMergeArr2(){
    int A[8] = {1,3,5};
    int B[4] = {2, 4, 6, 7};
    mergeArr2(A, 8, B, 4);
    display(A, 8);
}

int main(void){
    testMergeArr1();
    testMergeArr2();
    return 0;
}