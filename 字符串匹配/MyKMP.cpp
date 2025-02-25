#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
char P[MAXN], T[MAXN]; // P为模式串，T为文本串
int m, n, q;           // m为模式串长度，n为文本串长度
int pi[MAXN];          // pi[q]：前缀Pq的前缀Pk是前缀Pq的后缀（最长的）
// Gary：字符串P的长度为q的前缀，它的前缀等于后缀的最小长度
void compute_prefix_function() // 求解p[q]，与T毫无关系
{
    pi[1] = 0;
    int k = 0;
    for (q = 2; q <= m; q++)
    {
        while (k > 0 && P[k + 1] != P[q])
            k = pi[k]; // 如果失配，那么就不断向回跳，直到可以继续匹配
        if (P[k + 1] == P[q])
            k++;
        pi[q] = k;
    }
}
void KMP_matcher()
{
    compute_prefix_function();
    q = 0;
    for (int i = 1; i <= n; i++) // 匹配文本串
    {
        while (q > 0 && P[q + 1] != T[i])
            q = pi[q];
        if (P[q + 1] == T[i])
            q++;
        if (q == m)
        {
            cout << i - m + 1 << '\n'; // 从小到大输出P在T中出现的位置，下标1开始
            q = pi[q];
        }
    }
}
/** P和T下标分别从0开始的 **/
void compute_prefix_function0() // 求解p[q]，与T毫无关系
{
    pi[0] = 0;
    int k = 0;
    for (q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
            k = pi[k - 1]; // 如果失配，那么就不断向回跳，直到可以继续匹配
        if (P[k] == P[q])
            k++;
        pi[q] = k;
    }
}
void KMP_matcher0()
{
    compute_prefix_function0();
    q = 0;
    for (int i = 0; i < n; i++) // 匹配文本串
    {
        while (q > 0 && P[q] != T[i])
            q = pi[q - 1];
        if (P[q] == T[i])
            q++;
        if (q == m)
        {
            cout << i - m + 1 << '\n'; // 从小到大输出P在T中出现的位置，下标1开始
            q = pi[q - 1];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> (P + 1) >> (T + 1);
    m = strlen(P + 1), n = strlen(T + 1);
    KMP_matcher();
    /*下标从0开始：
    cin >> P >> T;
    m = strlen(P), n = strlen(T);
    KMP_matcher0();
    */
   
    // for (int i = 1; i <= m; i++)
    //     cout << pi[i] << ' ';
    return 0;
}