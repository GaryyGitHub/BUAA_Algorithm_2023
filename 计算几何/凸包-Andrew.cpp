#include <bits/stdc++.h>
using namespace std;
#define MAXN 100006
typedef long long ll;
struct point
{
    ll x, y;
} p[MAXN], s[MAXN], p0; // s是栈，实际上是数组
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
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
bool cmp2(point &a, point &b)
{
    if (direction(p0, a, b) > 0)
        return false;
    return true;
}
// 横坐标第一关键字，纵坐标第二关键字，则最小和最大元素一定在凸包上
// 升序枚举求下凸壳，降序求上凸壳
void Andrew_scan(int n)
{
    sort(p + 1, p + 1 + n, cmp);
    int t = 0, top = 0, i;
    for (i = 1; i <= n; i++)
    {
        while (top > 1 && direction(s[top - 1], s[top], p[i]) >= 0) // 叉积>0，右转
            top--;
        s[++top] = p[i];
    }
    t = top;
    for (i = n - 1; i >= 1; i--)
    {
        while (top > t && direction(s[top - 1], s[top], p[i]) >= 0)
            top--;
        s[++top] = p[i];
    }
    // 此时，栈s中存储的是凸包上所有的点！！
    // 下面，求凸包围成的面积
    ll res = 0;
    for (i = 2; i < top - 1; i++)
        res += direction(s[1], s[i], s[i + 1]);
    if (res % 2 == 0)
        cout << abs(res) / 2 << ".0\n"; // 这个巧妙
    else
        cout << abs(res) / 2 << ".5\n";
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
    // 此时，栈s中存储的是凸包上所有的点！！
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
        for (i = 1; i <= n; i++)
            cin >> p[i].x >> p[i].y;
        Andrew_scan(n);
    }
    return 0;
}
/*
样例输入：
2
4
-1000000000 -1000000000
-1000000000 1000000000
1000000000 1000000000
1000000000 -1000000000
5
1 0
0 1
1 1
2 1
1 2
样例输出：
4000000000000000000.0
2.0
*/