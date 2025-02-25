#include <bits/stdc++.h>
using namespace std;
#define MAXN 100006
typedef long long ll;
struct point
{
    ll x, y;
} p[MAXN], s[MAXN], p0;
ll direction(point pi, point pj, point pk)
{ //(pk-pi)x(pj-pi)为正，pk在pj的逆时针方向上
    ll x1 = (pk.x - pi.x);
    ll y1 = (pk.y - pi.y);
    ll x2 = (pj.x - pi.x);
    ll y2 = (pj.y - pi.y);
    return x1 * y2 - x2 * y1;
}
bool cmp(point &a, point &b)
{
    return a.y != b.y ? a.y < b.y : a.x < b.x;
}
bool cmp2(point &a, point &b)
{
    if (direction(p0, a, b) > 0)
        return false;
    return true;
}
void Graham_scan(int n)
{
    sort(p, p + n, cmp);
    p0 = p[0];
    int top = 0, i;
    sort(p + 1, p + n, cmp2);
    // cout << '\n';
    // for (i = 0; i < n; i++)
    //     cout << p[i].x << " " << p[i].y << '\n';
    s[++top] = p[0];
    s[++top] = p[1];
    s[++top] = p[2];
    for (i = 3; i < n; i++)
    {
        while (direction(s[top - 1], s[top], p[i]) > 0)
        {
            top--;
        }
        s[++top] = p[i];
    }
    // for (i = 1; i <= 4; i++)
    //     cout << s[i].x << ' ' << s[i].y << '\n';
    // 此时，栈s中存储的是凸包上所有的点！！下面，计算凸包面积
    ll res = 0;
    for (i = 2; i <= top - 1; i++)
        res += direction(s[1], s[i], s[i + 1]);
    if (res % 2 == 0)
        cout << abs(res) / 2 << ".0\n";
    else
        cout << abs(res) / 2 << ".5\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(p, 0, sizeof(p));
        memset(s, 0, sizeof(s));
        int n, i;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        Graham_scan(n);
    }
    return 0;
}