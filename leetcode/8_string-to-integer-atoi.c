//  字符串转换整数 (atoi)
// https://leetcode-cn.com/problems/string-to-integer-atoi/

#include <stdio.h>

int myAtoi(char* str) {
    if (str == NULL || *str == '\0'){
        return 0;
    }
    int INT_MAX = (~(unsigned int)0)/2;
    int INT_MIN = (~(unsigned int)0)/2 + 1;
    int flag = 1;
    while (*str == ' ') str++;

    if(*str == '+'){
        flag = 1;
        str++;
    }
    if(*str == '-'){
        flag = -1;
        str++;
    }
    int num = 0;
    while (*str != '\0')
    {
        int n = *str - '0';

        if(n < 0 || n > 9) break;

        if(n > INT_MAX / 10 || (n == INT_MAX / 10 && n > 7)){
            return flag > 0 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + n;
        str++;
    }
    printf("===%d\n",num);
    return flag * num;
}

int main(int argc, char const *argv[])
{
    printf("=== %d \n", myAtoi("-204043wwe"));
    return 0;
}
