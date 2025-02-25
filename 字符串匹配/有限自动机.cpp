#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
char P[MAXN], T[MAXN];        // P为模式串，T为输入文本
int delta[MAXN][30] = {0};    // 有限状态转换表
int alphabet[MAXN], alphaNum; // 有限输入字母表，检测哪些字母输进去了
int i, j, q, m, n;
// C6 I: 假设全都是小写字母
// 此算法时间复杂度很高
int prefix_judge(int k, int q, char a)
{
    if (k - q > 1) // Pk长度甚至大于Pqa
        return 0;
    if (P[k] != a) // 先检验Pk的末位和a是不是相等
        return 0;
    // 然后遍历，依次比较，看Pk是不是Pqa的后缀
    for (int i = k - 1, j = q; i >= 1 && j >= 1; i--, j--)
        if (P[i] != P[j])
            return 0;
    return 1;
}
void print_state_form()
{
    cout << "State" << '\t';
    for (j = 0; j < 26; j++)
        if (alphabet[j] == 1)
            cout << (char)(j + 'a') << '\t';
    cout << "P" << '\n';
    for (i = 0; i <= m; i++)
    {
        cout << i << '\t';
        for (j = 0; j < 26; j++)
            if (alphabet[j] == 1)
                cout << delta[i][j] << '\t';
        cout << P[i + 1] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> (P + 1) >> (T + 1);
    m = strlen(P + 1), n = strlen(T + 1);
    for (i = 1; i <= m; i++)
        if (alphabet[P[i] - 'a'] == 0)
        {
            alphabet[P[i] - 'a']++;
            alphaNum++;
        }
    // COMPUTE_TRANSITION_FUNCTION
    for (q = 0; q <= m; q++)
        for (i = 0; i < 26; i++)
            if (alphabet[i] == 1)
            {
                int k = min(m + 1, q + 2);
                while (!prefix_judge(k, q, i + 'a') && k > 0)
                    k--;
                delta[q][i] = k;
            }
    print_state_form();
    // FINITE_AUTOMATION_MATCHER
    q = 0;
    for (i = 1; i <= n; i++)
    {
        q = delta[q][T[i] - 'a'];
        if (q == m)
            cout << i - m << ' '; // 打印下标从零开始的所有匹配点
    }
    return 0;
}