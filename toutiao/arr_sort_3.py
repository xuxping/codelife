# https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1017/
# 搜索旋转排序数组
# 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        if length == 1:
            return 0 if nums[0] == target else -1
        
        low = 0
        high = length - 1
        
        while low <= high:
            mid = (low + high) >> 1
            
            if(nums[mid] == target):
                return mid
            
            if nums[0] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] < target <= nums[length - 1]:
                    low = mid + 1
                else:
                    high = mid - 1

        return -1