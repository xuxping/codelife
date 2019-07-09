/**
 * 将字符串转化为数字，atoi的实现
 * 《剑指offer》案例一
 * 考虑的情况：
 *  1、只有0-9可以转化
 *  2、正负
 *  3、整数溢出
 *  4、输入为NULL,或者为空的情况，返回值为0的情况
 */
#include <stdio.h>

enum Status {kValid=0, kInvalid};

//使用全局变量来表明错误类型，区分返回为0和异常的情况
int g_nStatus = kValid;

long long StrToIntCore(char *str, int flag){
    long long num = 0; // 使用long long型，防止整数溢出，程序挂掉
    while(*str != '\0'){

        if (*str == ' '){ //跳过空字符
            str++;
            continue;
        }
        // 只有0-9才可以转化
        if(*str >= '0' && *str <= '9'){
            num = num*10 + flag * (*str - '0');
            // 0x80000000为最小的负整数，0x7FFFFFFF为最大的负整数
            if ((flag == -1 && num < (signed int)0x80000000 )|| 
                (flag == 1 && num > 0x7FFFFFFF)){
                    num = 0;
                    break;
            }
            str++;
        }else{
            num = 0;
            break;
        }
    }

    if (*str == '\0'){
        g_nStatus = kValid;
    }

    return num;
}


int StrToInt(char *str){
    g_nStatus = kInvalid;
    long long num = 0;
    if (str != NULL && *str != '\0'){
        int flag = 1; // 1为正数，-1为负数
        while(str == ' '){
            str++;
        }

        if(*str == '+'){
            str++;
        }else if(*str == '-'){
            str++;
            flag = -1; // 负数
        }

        if (*str != '\0'){
            num = StrToIntCore(str, flag);
        }
    }
    return (int)num;
}


int main(void){
    char *str = "-89004139";
    int num = StrToInt(str);
    printf("num == %d\n", num);
    printf("g_nStatus == %d\n", g_nStatus);
    return 0;
}