// 两数之和
// https://leetcode-cn.com/problems/two-sum/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 暴力解法时间复杂度:O(n^2)
 * 也可以使用空间换时间的解法，采用Hash算法，不够c需要自己实现hash表
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *res = malloc(2*sizeof(int));
    for(int i = 0; i < numsSize - 1; i++){
        for (int j = i + 1; j < numsSize; j++){
            if(nums[j] ==  (target - nums[i])){
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}


int main(void){
    const int numsSize = 10;
    int nums[numsSize] = {2 ,7,8,2,6,67,2,33,4564,6};
    int *res = twoSum(nums, numsSize, 9);
    printf("%d, %d\n", res[0], res[1]);
 
}
