// utils.h

#ifndef UITLS_H
#define UITLS_H


void swap(int *a, int *b);

void display(int *arr, int arrSize);

// 随机生成start~end之间的数字
int rand_idx(int start, int end);

// 获取当前时间(s)
unsigned long gettime();

/**
 * 创建随机数组
 */
int *createRandomArr(int arrSize);

#endif // UITLS_H