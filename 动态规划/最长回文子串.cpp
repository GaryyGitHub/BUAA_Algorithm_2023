#include <bits/stdc++.h>
using namespace std;
char s[2005];
int dp[2005][2005]; // 起始为i，终末为j的字符串是否为回文串
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        cin >> s;
        int n = strlen(s), len, i, j;
        for (len = 1; len <= n; len++)
        {
            for (i = 0; i <= n - len; i++)
            {
                j = i + len - 1;
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j] && dp[i + 1][j - 1] == len - 2)
                    dp[i][j] = len;
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
输入样例
3
asdfdsaasdfdsa
aba
aabb
输出样例
14
3
2
*/