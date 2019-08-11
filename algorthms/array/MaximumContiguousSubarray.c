/**
求数组的子数组最大累加和.
test size:1000
------------------------------
algorithm1-->
    max v: 3049
    speed: 403.000000ms
algorithm2-->
    max v: 3049
    speed: 2.000000ms
algorithm3-->
    max v: 3049
    speed: 0.000000ms

test size:10000
------------------------------
algorithm1-->
    max v: 4814
    speed: 389174.000000ms
algorithm2-->
    max v: 4814
    speed: 127.000000ms
algorithm3-->
    max v: 4814
    speed: 1.000000ms

test size:1000000
------------------------------
algorithm3-->
    max v: 19819
    speed: 104.000000ms
algorithm4-->
    max v:19819
    speed: 6.000000ms
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define INFINITY -255

/**
* T(n) = O(n^3)
*/
void algorithm1(int *arr, int len)
{
    int max = arr[0];
    int v = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            v = 0;
            for (int k = i; k <= j; k++)
            {
                v += arr[k];
            }
            if (v > max)
            {
                max = v;
            }
        }
    }
    printf("max v: %d\n", max);
}

/**
* T(n) = O(n^2)
*/
void algorithm2(int *arr, int len)
{
    int max = arr[0];
    int v = 0;
    for (int i = 0; i < len; i++)
    {
        v = arr[i];
        for (int j = i + 1; j < len; j++)
        {
            v += arr[j];
            if (v > max)
            {
                max = v;
            }
        }
        //printf("\n");
    }
    printf("max v: %d\n", max);
}

/**
 * 分而治之：最大的要么在左边，要么在右边，要么在左右中间
 * T(n) = O(nlog(n))
 */
int algorithm3(int *arr, int l, int r)
{
    if (l == r)
        return arr[l];

    int mid = (l + r) / 2;
    int s1 = algorithm3(arr, l, mid);
    int s2 = algorithm3(arr, mid + 1, r);

    int max = s1 > s2 ? s1 : s2;
    // [m, m+1]
    int left_max = INFINITY;
    int left_v = 0;
    for (int i = mid; i >= l; i--)
    {
        left_v += arr[i];
        if (left_v > left_max)
        {
            left_max = left_v;
        }
    }
    int right_max = INFINITY;
    int right_v = 0;
    for (int j = mid + 1; j <= r; j++)
    {
        right_v += arr[j];
        if (right_v > right_max)
        {
            right_max = right_v;
        }
    }
    int a = left_max + right_max;
    max = a > max ? a : max;
    return max;
}

/**
 * 不为0就一直累加
* T(n) = O(n)
*/
void algorithm4(int *arr, int len)
{
    int res = INFINITY;
    int cur = 0;
    for (int i = 0; i < len; i++)
    {
        cur += arr[i];
        res = res > cur ? res : cur;
        cur = cur < 0 ? 0 : cur;
    }
    printf("max v:%d\n", res);
}

/**
* 生成随机数组
*/
void random_arr(int *arr, int len)
{
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 200 - 100;
    }
}

long double get_millisecond()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(void)
{
    const int len = 10000;
    int arr[len];
    random_arr(arr, len);
    printf("test size:%d\n", len);
    long double t_start, t_end;
    
    printf("algorithm1-->\n");
    t_start = get_millisecond();
    algorithm1(arr, len);
    t_end = get_millisecond();
    printf("speed: %Lfms\n", t_end-t_start);

    printf("algorithm2-->\n");
    t_start = get_millisecond();
    algorithm2(arr, len);
    t_end = get_millisecond();
    printf("speed: %Lfms\n", t_end-t_start);
    
    printf("algorithm3-->\n");
    t_start = get_millisecond();
    int max = algorithm3(arr, 0, len - 1);
    printf("max v: %d\n", max);
    t_end = get_millisecond();
    printf("speed: %Lfms\n", t_end - t_start);

    printf("algorithm4-->\n");
    t_start = get_millisecond();
    algorithm4(arr, len);
    t_end = get_millisecond();
    printf("speed: %Lfms\n", t_end - t_start);

    return 0;
}
