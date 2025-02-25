#include <bits/stdc++.h>
using namespace std;
#define INF 9223372036854775800
long long p[1006], Min[1006][1006], Max[1006][1006], s[1006][1006];
// Min[1][n]为最优解，Max[1][n]为最坏解，s存储最优解分割点
// p为n个矩阵的规模，Ai=pi-1*pi
// matrix-chain multiplication
void printAns(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printAns(i, s[i][j]);
        printAns(s[i][j] + 1, j);
        cout << ")";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, i, j, l, k;
    cin >> n; // 矩阵的个数
    for (i = 0; i <= n; i++)
        cin >> p[i]; // 表示矩阵 Ai 的行数和列数为 ai 和 ai+1（前矩阵列数=后矩阵行数）
    for (i = 1; i <= n; i++)
        Min[i][i] = 0;
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            Min[i][j] = INF;
            for (k = i; k <= j - 1; k++)
            {
                long long q = Min[i][k] + Min[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < Min[i][j])
                {
                    Min[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            Max[i][j] = -1;
            for (k = i; k <= j - 1; k++)
            {
                long long q = Max[i][k] + Max[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q > Max[i][j])
                {
                    Max[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << Min[1][n] << endl;
    // cout << fixed << setprecision(4) << (double)Max[1][n] / Min[1][n] << endl;
    // C3-E 只要求输出上一行最多是最少的多少倍。下面输出最优解：
    printAns(1, n);
    return 0;
}