// 打印1到N之间的数字    
// 要考虑大数的问题
#include <stdio.h>

/**
 * 错误示例：
 * 1、n有可能非常大->大数问题
 */
void e_print1ToN(int n){
    int number = 1;
    int i = 0;
    while(i++ < n){
        number *= 10;
    }
    for( i = 1; i < number; i++){
        printf("%d\t", i);
    }
}


/**
 * 在字符串上做加法
 */
int increment(char *number, int nlen){
    int isOverFlow = 0;
    int nTakeOver = 0;

    for(int i = nlen - 1; i >= 0; i--){
        int nSum = number[i] - '0' + nTakeOver;
        // 个位上加一
        if (i == nlen - 1){
            nSum++;
        }

        if(nSum >= 10){
            if(i == 0){
                isOverFlow = 1;
            }else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }else{
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverFlow;
}


/**
 * 打印字符串
 */
void printNumber(char *number, int nlen){

    int isBeginOf0 = 1;
    for(int i = 0; i < nlen; ++i){
        if(isBeginOf0 && number[i] != '0'){
            isBeginOf0 = 0;
        }
        if(!isBeginOf0){
            printf("%c", number[i]);
        }
    }
    printf("\t");
   
}

/**
 * 1、在字符串表达的数字上模拟加法
 * 2、把字符串表达的数字打印出来
 * 
 * '000000000000', n位字符串
 * '000000000009', n位字符串
 * '000000000010', n位字符串 
 */
void print1ToN(int n){
    if(n <= 0 ) return ;
    // 初始化
    char number[n];
    for (int i = 0; i < n; ++i){
        number[i] = '0';
    }

    while(!increment(number, n)){
        printNumber(number, n);
    }
}


int main(void){
    int n = 2;
    scanf("%d", &n);
    print1ToN(n);
    return 0;
}
