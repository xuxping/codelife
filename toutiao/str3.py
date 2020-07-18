# https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1016/
# 字符串的排列

class Solution:
    
    
    def calindex(self, s1, s2):
        
        return ord(s1) - ord(s2)
        
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        
        # 采用数组来记录
        s1map = [0] * 26
        s2map = [0] * 26
        for i in range(0, len(s1)):
            s1map[self.calindex(s1[i] , 'a')] += 1  # ord(a) = 101
            s2map[self.calindex(s2[i] , 'a')] += 1
        def match(s1map, s2map):
            for j in range(0, len(s1map)):
                if s1map[j] != s2map[j]:
                    return False
            return True
        
        for i in range(0, len(s2) - len(s1)):
            if match(s1map, s2map):
                return True
            
            s2map[self.calindex(s2[i + len(s1)] , 'a')] += 1
            s2map[self.calindex(s2[i] , 'a')] -= 1
        
        return match(s1map, s2map)
            