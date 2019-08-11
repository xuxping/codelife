//  字符串转换整数 (atoi)
// https://leetcode-cn.com/problems/string-to-integer-atoi/

#include <stdio.h>

int myAtoi(char* str) {
    if (str == NULL || *str == '\0'){
        return 0;
    }
    int sign = 1;
    long long num = 0;
    // const int INT_MAX = ~(unsigned int)0/2;
    // const int INT_MIN = ~(unsigned int)0/2 + 1;
    int set_sign = 0; // 是否设置过正负
    int find_num = 0; //是否找到有效字符（+，-，1-9）
    // atoi
    while(*str != '\0'){
        if (*str == '+' && !set_sign && !find_num){
            ++str;
            set_sign = 1;
            find_num = 1;
            continue;
        }
        if (*str == '-' && !set_sign && !find_num){
            ++str;
            sign = -1;
            find_num = 1;
            set_sign = 1;
            continue;
        }
        if(*str == ' ' && !find_num){
            ++str;
            continue;
        }
        // 非法字符
        if (!(*str >= '0' && *str <= '9')){
            break;
        }

        num = num * 10 + (*str - '0');
        find_num = 1;
        if(sign > 0 && num > INT_MAX){
            return INT_MAX;
        }
        if(sign < 0 && sign * num < INT_MIN){
            return INT_MIN;
        }
        str++;
    }
    return sign * num;
}