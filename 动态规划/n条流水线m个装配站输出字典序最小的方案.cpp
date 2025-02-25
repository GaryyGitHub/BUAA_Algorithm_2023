#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int p[12][22];       // 站点用时
int t[12][12];       // 站点间用时
long long f[12][22]; // 存储最优时间消耗
int l[12][22];       // 存储站点信息
int path[22];        // 存储每个站点在哪条流水线上
int main()
{
    /*本题思想：既然要输出字典序最小的，不妨从后往前（从右往左）动态规划
    这样到了最左端再从左往右遍历，决策权从左向右，符合字典序最小要求（左边尽可能小）
    */
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int m, n, i, j, k;
        cin >> m >> n;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                cin >> p[i][j];
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                cin >> t[i][j];
        for (i = 1; i <= n; i++)
        {
            f[i][m] = p[i][m];
            l[i][m] = i;
        }
        // f[1][m] = p[1][m], l[1][m] = 1;
        // f[2][m] = p[2][m], l[2][m] = 2;
        // f[3][m] = p[3][m], l[3][m] = 3;
        for (j = m - 1; j >= 1; j--) // 从右往左编号为j的装配站
        {
            for (i = 1; i <= n; i++) // 从1到n编号为i的流水线
            {
                f[i][j] = inf;
                for (k = 1; k <= n; k++) // 对流水线i，下一站（往左）若去往流水线k
                {
                    long long a = f[k][j + 1] + t[i][k] + p[i][j];
                    if (a < f[i][j])
                    {
                        f[i][j] = a;
                        l[i][j] = k;
                    }
                }
            }
        }
        long long ans = inf;
        int cur = 0;
        for (i = 1; i <= n; i++)
        {
            if (f[i][1] < ans)
            {
                ans = f[i][1];
                cur = i;
            }
        } // 此时ans为最优时间，cur是从右往左最后一个装配站的流水线序号
        for (i = 1; i <= m; i++)
        // 对装配站从左往右遍历，由于此前dp的时候挑选了当时情况下的最小流水线，故path依次存的就是字典序最小路径
        {
            path[i] = cur;
            cur = l[cur][i];
        }
        cout << ans << '\n';
        for (i = 1; i <= m; i++)
            cout << "Station" << i << ": Line" << path[i] << '\n'; // 别用endl！速度太慢了
    }
    return 0;
}
