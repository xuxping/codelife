// https://leetcode-cn.com/problems/reverse-words-in-a-string/
//  翻转字符串里的单词
/**
 * 思路：
 * 1、去除多余的空字符 
 * 2、翻转整个字符串串
 * 3、再次翻转每个单词
 */

#include <stdio.h>
#include <string.h>

char *reverseWords(char *s){
        printf("start=>%c", *s);

    char *temp = s;
    int slen = strlen(s);
    int start = 0;
        printf("start=>%d", start);
    // 找到第一不为空的字符下标
    while(*temp++ == ' '){
        printf("start=>%d", start);
        start++;
    }
    printf("start=>%d", start);
    // 整体移动字符串
    if (start != 0){
        int i = 0;
        for (int i = 0; i < slen - start; i++){
            // 去除多余的空格
            while(start > 0 && temp[start] == temp[start - 1] && temp[start] == ' '){
                start++;
            }
            if (start >= slen) break;

            s[i] = temp[start];
            start++;
        }

    }
    printf("remove space: %c\n", *s);
    return s;
}

int main(int argc, char const *argv[])
{
    char *s = "  hel   leofad  dfa fadfa   ";
    reverseWords(s);
    return 0;
}
