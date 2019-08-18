#include <stdio.h>
#include <stdlib.h>

char* convertToBase7(int num) {
    if (num==0) return "0";
    char *ret = (char *)malloc(sizeof(char) * 100);
    int top = -1;
    int s_num = num;
    int c = 0;
    num = num >= 0 ? num : -num;
    while (num > 0){
        c = num % 7;
        top += 1;
        ret[top] = c + '0';
        num = num / 7;
    }
    if(s_num < 0){
        top += 1;
        ret[top] = '-'; 
    }
    char *s = (char *)malloc(sizeof(char) * (top+1));
    for(int i = 0; i <= top; i++){
        s[i] = ret[top-i];
    }
    free(ret);
    ret = NULL;
    return s;
}

int main(void){
    char *ret = convertToBase7(-324324);
    printf("ret===>%s\n", ret);


    return 0;
}
