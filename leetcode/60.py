# https://leetcode-cn.com/problems/permutation-sequence/solution/
# 第K个排列

class Solution(object):

    def dfs(self, nums, length, depth, path, used, ans):
        if length == depth:
            return path
        
        # 当前层的排列数
        cur = self.factorial(length - depth - 1)
        for i in range(0, length):
            if used[i] is True:
                continue
            # 减枝
            if cur < k:
                k -= cur
                continue

            path.append(nums[i])
            used[i] = True
            return self.dfs(nums, length, depth + 1, path, used, ans)
        
        return None

    def factorial(self, n):
        total = 1
        while(n > 0):
            total *= n
            n -= 1
        
        return total

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0: return []
        ans = []
        path = []
        used = [False] * len(nums)
        return self.dfs(nums, len(nums), 0, path, used, ans)
        
            