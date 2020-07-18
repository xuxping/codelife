// 回文数
// https://leetcode-cn.com/problems/palindrome-number/
#include <stdio.h>

int isPalindrome(int x){
    // x小于0或者末尾为0
    if(x < 0 || (x != 0 && x % 10 == 0)) {
        return 0;
    }

    int reverseX = 0;
    while(x > reverseX){
        reverseX = reverseX * 10 + x % 10;
        x /= 10;
    }

    return x == reverseX || x == reverseX / 10;

}

int main(int argc, char const *argv[])
{
    printf("12344321 is palindrome: %d\n", isPalindrome(12344321));
    printf("124321 is palindrome: %d", isPalindrome(124321));
    return 0;
}
