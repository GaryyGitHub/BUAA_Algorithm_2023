#include <stdio.h>
#include <stdlib.h>

long long fpm(long long a, long long b, long long m)
{
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1) // 选取二进制为1对应的幂来相乘
            ans = ans * a % m;
    return ans;
} // 求解a^b mod m, m为素数
int main()
{
    long long a = 3, b = 998244351, m = 998244353;

    printf("%lld", (5 * fpm(a, b, m)) % m);
    return 0;
}