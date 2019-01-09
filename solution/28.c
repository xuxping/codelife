#include <stdio.h>

int strStr(char* haystack, char* needle) {
    if(*haystack=='\0' || *needle=='\0'){
        return 0;
    }
    
    int i = 0;
    int j = 0;
    
    while(haystack[j] != '\0'){
         printf("haystack[]---%c\n", haystack[j]);
        if(haystack[j] == needle[i]){
            printf("---%c", haystack[j]);
            printf("---%c\n", needle[i]);
            if(needle[i+1] == '\0'){
                return j - i;
            }
            i++;
        j++;
        }else{
            j = j-i +1;
            i = 0;
        }
    }
    return -1;
}

int main(void){
    //int r = strStr("", "");
    //int r = strStr("hello", "ll");
    int r = strStr("mississippi", "issip");
    printf("====%d", r);
    return 0;
}
