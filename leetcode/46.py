# https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
# 给定一个 没有重复 数字的序列，返回其所有可能的全排列


class Solution(object):

    def dfs(self, nums, length, depth, path, used, ans):
        if length == depth:
            ans.append(path)
            return
        
        for i in range(0, length):
            if used[i] is True:
                continue

            path.append(nums[i])
            used[i] = True
            self.dfs(nums, length, depth + 1, path, used, ans)
            path.pop()
            used[i] = False


    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0: return []
        ans = []
        path = []
        used = [False] * len(nums)
        self.dfs(nums, len(nums), 0, path, used, ans)
        return ans
        
            