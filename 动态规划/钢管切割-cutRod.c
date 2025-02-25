#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000000003
long long p[10006];
long long r[10006]; // 最优切割方案
int s[10006];       // 切割方案
int cnt;            // 把钢管切成cnt段
long long rod(long long p[], int n)
{
    for (int i = 0; i < 10005; i++)
        s[i] = 0;
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        long long q = -INF;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i] + r[j - i])
            {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld", &p[i]);
    // 第一行一个正整数，表示最大总销售价格。
    printf("%lld\n", rod(p, n));
    i = n;
    while (i > 0)
    {
        cnt++;
        i = i - s[i];
    }
    i = n;
    // 第二行一个正整数 k，表示钢管被分割成 k 段。
    printf("%d\n", cnt);
    // 第三行 k 个正整数 a1,…,ak，表示钢管的分割方式，需保证 ∑ai=n
    while (i > 0)
    {
        printf("%d ", s[i]);
        i = i - s[i];
    }
    return 0;
}