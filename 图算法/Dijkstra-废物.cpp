#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
const ll INF = 2e18;
vector<vector<PIL>> graph; // 数对，存储相邻定点和边的权重weight
int verNum;                // 顶点个数
vector<ll> dist;           // 距离，前置节点
vector<bool> vis;
priority_queue<PLI, vector<PLI>, greater<PLI>> Q;
void INIT(int s)
{
    for (int i = 0; i <= verNum; i++)
        dist[i] = INF;
    dist[s] = 0;
}
void insertEdge(int u, int v, ll weight)
{
    graph[u].emplace_back(v, weight);
} // 一个是邻接表，一个是边数组
void DIJKSTRA(int s)
{
    INIT(s);
    Q.push({0, s});
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto v : graph[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                Q.push({dist[v.first], v.first});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    insertEdge(1, 2, 10);
    insertEdge(2, 3, 1);
    insertEdge(2, 4, 2);
    insertEdge(1, 4, 5);
    insertEdge(4, 2, 3);
    insertEdge(4, 5, 2);
    insertEdge(5, 1, 7);
    insertEdge(3, 5, 4);
    insertEdge(4, 3, 9);
    insertEdge(5, 3, 6);
    verNum = 5;
    // DIJKSTRA(1);
    // for (int i = 0; i < verNum; i++)
    //     cout << dist[i] << " ";
    cout << "23423";
    return 0;
}