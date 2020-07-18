# https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1014/
# 最长公共前缀


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs or not strs[0]:
            return ""
        
        ans = ""
        i = 0
        for p in strs[0]:
            for s in strs[1:]:
                if i >= len(s) or s[i] != p:
                    return ans
            ans += p
            i += 1
        return ans