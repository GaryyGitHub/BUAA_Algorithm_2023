#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int pi[MAXN], out[MAXN];
char P[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        memset(pi, 0, sizeof(pi));
        cin >> (P + 1);
        int m = strlen(P + 1);
        pi[1] = 0;
        int k = 0;
        for (int q = 2; q <= m; q++)
        {
            while (k > 0 && P[k + 1] != P[q])
                k = pi[k]; // 如果失配，那么就不断向回跳，直到可以继续匹配
            if (P[k + 1] == P[q])
                k++;
            pi[q] = k;
        }
        /*正常kmp算前缀函数
        由前缀函数pi定义：前缀中最长的使得真前缀与真后缀相等的长度
        因此最大解为m，次大解为pi[m]，
        把次大解作为新的最大解，则它的次大解为pi[pi[m]]，
        以此类推，递推到pi[pi[pi...pi[m]]]==0时结束，
        0的前一项就是最小的解，第一项是最大的解，逆序输出即可*/
        int fuck = m, sum = 0;
        out[sum++] = fuck;
        while (fuck > 0)
        {
            out[sum++] = pi[fuck];
            fuck = pi[fuck];
        }
        for (int i = sum - 2; i >= 0; i--)
            cout << out[i] << ' ';
        cout << '\n';
    }
    return 0;
}
/*
样例输入：
3
aaaaa
abcdabcd
hsah
样例输出：
1 2 3 4 5
4 8
1 4
*/