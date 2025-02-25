#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int father[100005]; // 并查集
typedef struct d
{
    int u, v;
    ll w;
} D;
D edge[500005];
bool cmp(D a, D b) { return a.w < b.w; }
int Find(int i) // 找最先祖先，需要在这里更新！！
{
    if (father[i] == i)
        return father[i];
    return father[i] = Find(father[i]);
} // 递归寻找一个节点的祖先，若祖先就是自己则返回
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        ll ans = 0;
        cin >> n >> m;
        for (i = 1; i <= n; i++)
            father[i] = i; // 初始时，每个点都是单独的连通分量
        for (i = 0; i < m; i++)
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
        sort(edge, edge + m, cmp);
        for (i = 0; i < m; i++)
        {
            int u = edge[i].u, v = edge[i].v;
            int visu = Find(u), visv = Find(v); // 分别为u和v的祖先
            if (visu != visv)                   // 若两个点有共同祖先，则不能将边加进去
            {
                father[visu] = Find(visv); // u和v的祖先均改为v的祖先，合并操作，可写成merge函数
                ans += edge[i].w;
            }
            // for (int j = 1; j <= n; j++)
            //     cout << father[j];
            // cout << '\n';
        }
        cout << ans << '\n'; // 输出最短路径长度
    }
    return 0;
}