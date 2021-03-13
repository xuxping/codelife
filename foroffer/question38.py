# 字符串的排列
# 输入一个字符串，打印出该字符串中字符的所有排列。

class Solution:
    def permutation(self, s: str) -> List[str]:
        strs, ans = list(s), []

        def dfs(x):
            if x == len(strs) - 1:
                ans.append(''.join(strs))
                return
            
            occur = set()
            for i in range(x, len(strs)):
                if strs[i] in occur:
                    continue
                
                occur.add(strs[i])
                strs[i], strs[x] = strs[x], strs[i]
                dfs(x + 1)
                strs[i], strs[x] = strs[x], strs[i]
        dfs(0)
        return ans                