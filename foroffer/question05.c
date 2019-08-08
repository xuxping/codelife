// 替换空格
// 将字符串中的空格都替换成”%20“，比如”we are happy" 输出为 “we%20are%20happy”
#include <stdio.h>

/**
 * 从后面移动字符串
 * T(n) = O(n)
 * 1. 如何求字符串长度‘\0’，如果字符串中本身就有'\0'，如何保证二进制安全？
 */
void replaceBlank(char *str, int strlen)
{
    if (str == NULL || strlen <= 0) return;

    int numberOfBlank = 0;
    int originLen = 0; // str的实际长度
    int i = 0;
    while(str[i] != '\0')
    {
        ++originLen;
        if (str[i] == ' '){
            ++numberOfBlank;
        }
        ++i;
    }
    // 将空格换成”%20“后的长度
    int newlen = originLen + 2 * numberOfBlank;
    if (newlen > strlen) return;

    /**
     * 为什么要重新赋值给新的变量，语义不同
     */
    int idxOfNew = newlen;
    int idxOfOrigin = originLen;

    while(idxOfOrigin >= 0 && idxOfNew >= idxOfOrigin){
        if (str[idxOfOrigin] == ' '){
            str[idxOfNew--] = '0';
            str[idxOfNew--] = '2';
            str[idxOfNew--] = '%';
        }else{
            str[idxOfNew--] = str[idxOfOrigin];
        }
        --idxOfOrigin;
    }
}


int main(void){
    const int STR_LEN = 40;
    // char str[STR_LEN] = {'w','e',' ', 'a','r','e',' ','h','a','p','p','y'};
    char str[STR_LEN];
    printf("input you str: ");
    gets(str);
    printf("input str: %s\n", str);

    replaceBlank(str, STR_LEN);
    printf("output str: %s\n", str);
}