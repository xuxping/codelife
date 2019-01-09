#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    if(s == NULL){
        return 0;
    }
    char *p = s;
    int i = 0, j = 0, start = 0, end = 1, max = 1;
    int sLen = 0;
    while(*p++ != '\0'){
        sLen++;
        // p++;
    }
    printf("s len --> %d\n", sLen);
    for(i = 1; i < sLen; i++){
        for(j  = start; j < end; j++){
            // 有重复
            if (s[i] == s[j]){
                printf("start-->%d, end-->%d\n", start,end);
                start = j + 1;
                break;
            }
        }
        end = i + 1;
        if(end - start> max){
            max = end - start;
        }
    }
    return max;
    
}

int main(void){
    char *s = "abcabcbb";
   // char *s = "bbbbb";
   //char *s = "pwwkew";
   int sLen = lengthOfLongestSubstring(s);
   printf("max len == %d\n", sLen);

}
