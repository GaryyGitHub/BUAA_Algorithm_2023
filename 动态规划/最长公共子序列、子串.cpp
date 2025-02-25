#include <bits/stdc++.h>
using namespace std;
char s1[2005], s2[2005];
char subsequence[2005], substring[2005];
int f[2005][2005]; // 最长公共子串LCsubstring，删去一段前缀和一段后缀得到
// f[i][j]表示子串s1[0,i-1](第i个字符结尾)和子串s2[0,j-1]的最长公共子串
int g[2005][2005]; // 最长公共子序列LCSequence，删去字符得到，更宽泛
// g[i][j]同上，只不过是最长公共子序列
int flag1, flag2[2005][2005];
// flag1存储最后一位两字符串相等的位置
// flag2存储
int LCSubstring()
{
    int res = 0, i, j;
    int m = strlen(s1), n = strlen(s2);
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            { // s1[i-1]==s2[j-1]，最长子串就是前面子串加上该字符
                f[i][j] = f[i - 1][j - 1] + 1;
                if (res <= f[i][j])
                {
                    res = f[i][j];
                    flag1 = i; // 只要res增加就更新flag1位置
                }
                res = max(f[i][j], res);
            } // res时刻存储最长的子串
            else
                f[i][j] = 0;
        }
    }
    return res;
}
int LCSubsequence() // 最长公共子序列，算导上的
{
    int i, j, m = strlen(s1), n = strlen(s2);
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1]) // 只有这一步是真正增加了子序列长度
            {
                g[i][j] = g[i - 1][j - 1] + 1;
                flag2[i][j] = 0;
            }
            else if (g[i - 1][j] > g[i][j - 1]) // 这步和下一步只是更新g[i][j]
            {
                g[i][j] = g[i - 1][j];
                flag2[i][j] = 1;
            }
            else
            {
                g[i][j] = g[i][j - 1];
                flag2[i][j] = -1;
            }
        }
    }
    return g[m][n];
}
int cnt2; // cnt2就是当前子序列的位置
void PrintLCSequence(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (flag2[i][j] == 0)
    {
        PrintLCSequence(i - 1, j - 1);
        subsequence[cnt2] = s1[i - 1];
        cnt2++;
        // cout << s1[i - 1];//去掉注释就是直接输出
    }
    else if (flag2[i][j] == 1)
        PrintLCSequence(i - 1, j);
    else
        PrintLCSequence(i, j - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        memset(subsequence, 0, sizeof(subsequence));
        flag1 = 0;
        cnt2 = 0;
        memset(flag2, 0, sizeof(f));
        cin >> s1 >> s2;

        int ans = LCSubstring();
        cout << ans << "\n";
        for (int i = flag1 - ans; i < flag1; i++)
            cout << s1[i];

        cout << '\n'
             << LCSubsequence() << "\n";
        PrintLCSequence(strlen(s1), strlen(s2));
        cout << subsequence << '\n';
    }
    return 0;
}
/*样例输入：
2
iwannafuckyouoff
youaresonofabitch
lapispureruby
jadestarsepia
样例输出：
3
you
5
youof
2
pi
4
asre*/