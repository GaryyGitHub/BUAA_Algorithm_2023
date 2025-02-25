#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
const ll inf = 2e18; // 2*10^18
class Dijstra
{
public:
    int n;
    vector<vector<PIL>> g; // 图的邻接表
    vector<long long> dis; // 各点到源点的距离
    Dijstra(int n)         // 迪杰斯特拉类的构造函数，即初始化
    {
        this->n = n;
        g.resize(n);
        dis.resize(n, inf);
    }
    void add(int u, int v, long long w) { g[u].emplace_back(v, w); }

    void solve(int s)
    {
        vector<bool> vis(n);                              // 是否已找到过，找到过则为true
        priority_queue<PLI, vector<PLI>, greater<PLI>> q; // 小顶堆优先队列，分别为与源点距离、点序号
        dis[s] = 0;                                       // 源点距离置为0
        q.push({0, s});                                   // 将源点距离、序号存入优先队列
        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = true; // 相当于S=S∪{u}
            for (auto e : g[u])
            {
                int v = e.first;
                ll w = e.second;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s; // n=结点数，m=边数，s=源点编号
    cin >> n >> m >> s;
    // --s;
    Dijstra dj(n + 1); // 构建Dijkstra类实例，注意！！！此处是n+1，涉及到q、dis、vis的初始化
    for (int i = 0; i < m; i++)
    {
        int x, y, w; // x,y为边的两端，w为weight
        cin >> x >> y >> w;
        // --x; //如构造实例不传入n+1，则s x y均需减1，且后面输出是i+1
        // --y;
        dj.add(x, y, w); // 无向图，插入两遍
        dj.add(y, x, w);
    }
    dj.solve(s); // 调用solve方法，s为源点
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        cout << dj.dis[i] << " ";
    }
    return 0;
}
// 样例：
/*
5 5 1
1 2 5
3 5 8
3 2 1
1 3 2
2 5 6
*/