/**
判断一个表达式的括号是否匹配？   
如表达式`34+[(13*9+44)-(12/3)]`   
方案：
用栈来保存未匹配的左括号，从左到右依次扫描字符串。当扫描到左括号时，则将其压入栈中；
当扫描到右括号时，从栈顶取出一个左括号。如果能够匹配，比如“(”跟“)”匹配，“[”跟“]”匹配，
“{”跟“}”匹配，则继续扫描剩下的字符串。如果扫描的过程中，遇到不能配对的右括号，或者
栈中没有数据，则说明为非法格式。当所有的括号都扫描完成之后，如果栈为空，则说明字符串为
合法格式；否则，说明有未匹配的左括号，为非法格式。  
*/

#include <stdio.h>

/**
 * 是否是左括号
 */
int isLeftBrackets(char ch){
    int isLeft = 0;

    if(ch == '{' || ch == '[' || ch == '('){
        isLeft = 1;
    }

    return isLeft;
}

/**
 * 是否是右括号
 */
int isRightBrackets(char ch){
    int isRight = 0;

    if(ch == '}' || ch == ']' || ch == ')'){
        isRight = 1;
    }

    return isRight;
}

/**
 * 两个括号是否匹配
 */ 
int isLeftMatchRight(char left, char right){
    int isMatch = 0;
    if((left == '{' && right == '}') ||
        (left == '[' && right == ']') ||
        (left == '(' && right == ')')){
        isMatch = 1;
    }
    
    return isMatch;
}


int isBracketsMatch(char *str){
    if(str == NULL || *str == '\0'){
        return 0;
    }

    int isMatch = 0;

    char stack[100];
    int top = -1;

    while (*str != '\0'){
        if(isLeftBrackets(*str)){
            stack[++top] = *str;
        }else if(isRightBrackets(*str) && top >= 0){
            if(isLeftMatchRight(stack[top], *str)){
                printf("%c - %c\n", stack[top], *str);
                top--;
            }else{
                isMatch = 0;
                break;
            }
        }
        str++;
    }

    if(top < 0){
        isMatch = 1;
    }

    return isMatch;
}

int main(void){
    char *str = "34+[(13*9+44)-(12/3)]";
    printf("str: %s\n", str);

    if(!isBracketsMatch(str)){
        printf("not match\n");
    }else{
        printf("match\n");
    }

    return 0;
}
