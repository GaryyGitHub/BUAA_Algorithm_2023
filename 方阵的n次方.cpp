#include <bits/stdc++.h>
#define maxn 130
typedef long long ll;
const int mod = 1e9 + 7;
using namespace std;
int n;
ll k, a[maxn][maxn], b[maxn][maxn], tmp[maxn][maxn];
// 思路：A^(k0*2^0 +...+ kn*2^n) = A^(k0*2^0) *...* A^(kn*2^n), k0,...,kn = 0 or 1
//  设置单位阵
void setI(ll a[130][130])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
}
// 将矩阵b复制到矩阵a中
void move(ll a[130][130], ll b[130][130])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = b[i][j];
}
// 计算矩阵乘法a*b，结果存储在tmp矩阵中
void multiply(ll a[130][130], ll b[130][130])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= mod;
            }
        }
}
void bpow(ll p)
{
    // 先将b置为单位阵
    setI(b);
    while (p)
    {
        if (p & 1) // p为奇数
        {          // 等价于b = b * a
            multiply(b, a);
            move(b, tmp);
        }
        // 等价于a = a * a
        multiply(a, a);
        move(a, tmp);
        p >>= 1; // p /= 2
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        k = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        bpow(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << b[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
