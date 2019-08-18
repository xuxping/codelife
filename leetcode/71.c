#include <stdio.h>
#include <stdlib.h>

void display(char *stack, int top){
    for(int i = 0; i <= top; i++){
        printf("%c", stack[i]);
    }
    printf("\n");
}

char* simplifyPath(char* path) {
    if(path == NULL) return NULL;

    int mSize = 0;
    char *p = path;
    while(*p != '\0'){
       p++;
       mSize++;
    }
    // init stack
    char *stack = (char *)malloc(sizeof(char) * mSize);
    for(int i = 0; i < mSize; i++){
        stack[i] = '0';
    }

    int top = -1;

    while(*path != '\0'){
        if(*path == '/'){
            // 处理 // 的情况
            if(top == -1 || stack[top] != '/'){
                stack[++top] = *path;
            }
        }else if(*path == '.'){
            // 处理 .. 的情况
            if(*(path + 1) == '.'){
                if(top >= 2){
                    top -= 2;
                }else if(top >= 1){
                    top--;
                }
                path ++;
            }
        }else{
            stack[++top] = *path;
        }
        path++;
        display(stack, top);
    }
    // 处理顶部为 / 的情况
    if(top>=1 && stack[top] == '/'){
       top--;
    }
    char *res = (char *)malloc(sizeof(char) * (top + 1));
    for(int i = top; i >= 0; i--){
        res[i] = stack[i];
    }
    free(stack);
    stack=NULL;
    return res;

}

int main(void){
    // char *s = "/a/./b/../../c/";
    char *s = "/..";
    // char *s = "/home//foo/";
    char *res = simplifyPath(s);
    printf("=== %s \n", res);
    return 0;
}
