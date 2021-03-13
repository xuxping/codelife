// 实现 pow(x, n) ，即计算 x 的 n 次幂函数
double calPower(double x, int n){
    if (n == 0) return 1;

    double half = calPower(x, n / 2);

    if(n%2==0) return half * half;
    else return x * half * half;
}

double myPower(double x, int n){
    return n >= 0 ? calPower(x, n) : 1.0 / calPower(x, -n);
}


double myPower2(double x, int n){
    if (n == 0) return 1;
    int rst = 1;
    if (n < 0){
        x = 1.0 / x;
        n = -n;
    }
    while (n)
    {
        if(n & 1)  rst *= x; // 不是偶数
        x *= x;
        n >> 1; // n /= 2;
    }
    return rst;
}


