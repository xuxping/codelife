// 最长公共前缀
// https://leetcode-cn.com/problems/longest-common-prefix/

#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize <= 0)
    {
        return "";
    }

    
    char *pstart = strs[0];
    char *pend = strs[0];

    int start = 0, end = 0;
    // 执行strs[0]的尾部
    while(*pend != '\0'){
        pend++;
        end++;
    }

    for(int i = 1; i < strsSize; ++i){
        int j = 0;
        char *str = strs[i];
        // while()
    }

    char *res = (char *)malloc(sizeof(char) * (end - start + 1));
    int idx = 0;
    while(pstart != pend){
        res[idx++] = *pstart;
        pstart++;
    }

    return res;
}