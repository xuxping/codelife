// 整数反转
// https://leetcode-cn.com/problems/reverse-integer/

#include <stdio.h>
#include <stdlib.h>


/**
 * 1、使用数学运算来模拟栈的行为
 * 2、做溢出检查:[-2**31~2**31-1]
 *
 */
int reverse(int x){
    int rev = 0;
    int pop = 0;
    // 计算INT最大和最小的值
    int INT_MAX = (~(unsigned int)0)/2;
    int INT_MIN = (~(unsigned int)0)/2 + 1;
    while(x != 0){
        pop = x % 10;
        x = x / 10;
        // 上溢
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)){
            return 0;
        }
        // 下溢
        if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)){
            return 0;
        }
        
        rev = rev * 10 + pop;
    }
    return rev;
}


int main(void){
    int n = 123;
    int n_rev = reverse(n);
    printf("%d, %d\n", n, n_rev);
    n = -123;
    n_rev = reverse(n);
    printf("%d, %d\n", n, n_rev);
    return 0;
}
