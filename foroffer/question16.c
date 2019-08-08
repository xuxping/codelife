// 数值的整数次方

#include <stdio.h>

double powerWithUnsignedExponent(double base,unsigned int exponent){
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base;
    }
    double result = powerWithUnsignedExponent(base, exponent >> 1);

    result *= result;
    if(exponent % 2 ==1){
        result *= base;
    }
    return result;
}

int g_InvalidInput = 1;
double myPow(double base, int exponent){
    g_InvalidInput = 0;
    if (base == 0.0 && exponent < 0){
        g_InvalidInput = 1;
        return 0.0;
    }

    // unsigned int 无符号整型
    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0){
        absExponent = (unsigned int)(-exponent);
    }

    double result = powerWithUnsignedExponent(base, absExponent);

    if(exponent < 0){
        result = 1.0 / result;
    }
    return result;
}


int main(void){
    double n = myPow(10.1,-2);
    if (g_InvalidInput){
        printf("invalid input!");
    }else{
        printf("%f\n", n);
    }
    return 0;
}