#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
char s[MAXN];        // 字母表：a-j
int delta[MAXN][10]; // 有限状态转换表
int i, j, q, m, pi[MAXN];
void compute_prefix_function() // 求解p[q]，与T毫无关系
{
    pi[1] = 0;
    int k = 0;
    for (q = 2; q <= m; q++)
    {
        while (k > 0 && s[k + 1] != s[q])
            k = pi[k]; // 如果失配，那么就不断向回跳，直到可以继续匹配
        if (s[k + 1] == s[q])
            k++;
        pi[q] = k;
    }
    // for (i = 1; i <= m; i++)
    //     cout << pi[i] << ' ';
    // cout << '\n';
}
int main()
{ // 输出自动转移方程
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> (s + 1);
    m = strlen(s + 1);
    compute_prefix_function();
    // COMPUTE_TRANSITION_FUNCTION
    for (j = 0; j < 10; j++)
        delta[0][j] = 0;
    delta[0][s[1] - 'a'] = 1; // 初始化自动机第一位为1
    for (q = 1; q <= m; q++)  // 我们遍历到m，但输出至m-1
    {
        for (j = 0; j < 10; j++) // for each a in alphabet
        {
            if (q < m && s[q + 1] == j + 'a')
                delta[q][j] = q + 1;
            else
                delta[q][j] = delta[pi[q]][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < 10; j++)
            cout << delta[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}