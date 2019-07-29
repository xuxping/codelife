// 归并排序
#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"


/**
* Merge arr[l:mid], arr[mid+1:r] 
*/
void merge_arr(int *arr, int l, int mid, int r)
{
   int tsize = r - l + 1;
   int tmp[tsize];
   int i = l;
   int j = mid + 1;
   int t = 0;

   while (i <= mid && j <= r)
   {
      if (arr[i] > arr[j])
      {
         tmp[t++] = arr[i++];
      }
      else
      {
         tmp[t++] = arr[j++];
      }
   }
   while (i <= mid)
   {
      tmp[t++] = arr[i++];
   }
   while (j <= r)
   {
      tmp[t++] = arr[j++];
   }

   for (i = 0; i < t; i++)
   {
      arr[l + i] = tmp[i];
   }
}

void merge_sort(int *arr, int l, int r)
{
   if (l >= r)
      return;

   int mid = (l + r) / 2;
   merge_sort(arr, l, mid);
   merge_sort(arr, mid + 1, r);
   merge_arr(arr, l, mid, r);
}


int main(void)
{
   const int arrSize = 100;
   int *arr = createRandomArr(arrSize);
   printf("before sort\n");
   display(arr, arrSize);

   unsigned long start_time = gettime();
   merge_sort(arr, 0, arrSize - 1);
   unsigned long end_time = gettime();

   printf("cost %lu ms\n", (end_time - start_time));
   printf("after sort\n");
   display(arr, arrSize);

   free(arr);
}