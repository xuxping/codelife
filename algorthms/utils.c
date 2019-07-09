// utils.c
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *arr, int arrSize)
{
   for (int i = 0; i < arrSize; ++i)
   {
      printf("%d\t", arr[i]);
   }
   printf("\n");
}

// 随机生成start~end之间的数字
int rand_idx(int start, int end)
{
   return rand() % (end + 1 - start) + start;
}

unsigned long gettime()
{
   struct timeval tv;
   gettimeofday(&tv, NULL);
   unsigned long time_in_micros = 1000 * tv.tv_sec + tv.tv_usec / 1000;
   return time_in_micros;
}