class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return
        
        mapList = [
            [], [], 
           ['a', 'b', 'c'], ['d','e','f'],
           ['g', 'h', 'i'], ['j','k','l'],
           ['m', 'n', 'o'], ['p','q','r', 's'],
           ['t', 'u', 'v'], ['w','x','y', 'z'],
          ]
        
        r = []
        for s in digits:
            if 2<= int(s) <= 9:
                r = self.recursion(r, mapList[int(s)]) 
                
        return r
    
    def recursion(self, r, items):
        """递归生成"""
        
        if not r:
            for item in items:
                r.append(item)
            return r
        else:
            st = []
            for i in r:
                for item in items:
                    st.append(i+item)
            return st
            

if __name__ == '__main__':
    s = Solution()
    p = s.letterCombinations("234")
    print (p)
