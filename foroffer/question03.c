// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/submissions/
// 找出数组中重复的数字。
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
#include <stdio.h>

/**
 * 用数组的下标进行判断
 */ 
int findRepeatNumber(int* nums, int numsSize){
    if(numsSize < 2 || numsSize > 100000|| nums == NULL) return -1;

    for(int i = 0; i < numsSize; ++i){
        
        while(nums[i] != i){
            // 重复
            if(nums[nums[i]] == nums[i]){
                return nums[i];
            }
            // 交换
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;
        }
    }
    return -1;
}