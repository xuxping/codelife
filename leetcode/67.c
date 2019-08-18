#include <stdlib.h>
#include <stdio.h>

char* addBinary(char* a, char* b) {
    int carry = 0;
    int ai = 0;
    int bi = 0;
    char *p1 = a;
    char *p2 = b;
    while(*p1 != '\0' ){
        ai++;
        p1++;
    }
    while(*p2 != '\0'){
        bi++;
        p2++;
    }
    if(p1!=a) p1--;
    if(p2!=b) p2--;

    int mSize = ai > bi ? ai + 1 : bi + 1;
    char *str = (char *)malloc(sizeof(char) * mSize);
    for(int i = 0; i < mSize; i++){
        str[i] = '0';
    }
    int sum = 0;
    int si = mSize - 1;
    while(p1 != a-1 && p2 != b-1){
        sum = (*p1 - '0' + *p2 - '0' + carry);
        str[si] = sum % 2 + '0';
        carry = sum / 2;
        p1--;
        p2--;
        si--;
    }
    while(p1 != a-1){
        sum = (*p1 - '0' + carry);
        carry = sum / 2;
        str[si] = sum % 2 + '0';
        p1--;
        si--;
    }
    while(p2 != b-1){
        sum = (*p2 - '0' + carry);
        carry = sum / 2;
        str[si] = sum % 2 + '0';
        p2--;
        si--;
    }
    if(carry==1){
       str[0] = '1';
       return str;
    }
    char *str1 = (char *)malloc(sizeof(char) * (mSize-1));
    for(int i = 1; i < mSize; i++){
        str1[i-1] = str[i];
    }
    free(str);
    return str1;
}


int main(void){
    char *a = "111011110";
    char *b = "110011010";

    char *s = addBinary(a, b);
    printf("=====%s\n", s);
    return 0;
}
