# https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1012/
# 无重复字符的最长子串

# 采用滑动窗口+set来进行重复判断

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        slen = len(s)
        occur = set()
        
        p = -1
        maxlen = 0
        for i in range(slen):

            if i != 0:
                occur.remove(s[i - 1])
            

            while p + 1 < slen and s[p + 1] not in occur:
                occur.add(s[p + 1])
                p += 1
                
            maxlen = max(maxlen, p - i + 1)
        return maxlen