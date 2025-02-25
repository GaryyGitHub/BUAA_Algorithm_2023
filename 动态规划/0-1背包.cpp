#include <bits/stdc++.h>
using namespace std;
long long v[10005], w[10005], f[10005], t, m;
long long dp[1005][1005];
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        memset(v, 0, sizeof(v));
        memset(w, 0, sizeof(w));
        memset(f, 0, sizeof(f));
        cin >> m >> t; // m商品数目 t背包容量
        for (int i = 1; i <= m; i++)
            cin >> v[i] >> w[i]; // w是重量,V是价值
        /*// 朴素：二维dp
        for (int i = 1; i <= m; i++) // 对第i个商品
        {
            for (int j = t; j >= 0; j--) // 目前背包容量为t
            {
                if (j >= w[i]) // 容量足够放下该商品，看放入或不放入哪个价值大
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                else // 放不下，只好不放入
                    dp[i][j] = dp[i - 1][j];
            }
        }
        cout << dp[m][t] << '\n';*/

        // 优化后：
        for (int i = 1; i <= m; i++)
            for (int k = t; k >= w[i]; k--)
                // 更新前，f[k]中存i-1的价值；更新后存i的价值，后续覆盖，再用不到i-1的值
                // 容量只需遍历到i的重量，再往下就放不下了，语句就是f[j]=f[j]
                f[k] = max(f[k], f[k - w[i]] + v[i]);
        cout << f[t] << '\n';
    }
    return 0;
}