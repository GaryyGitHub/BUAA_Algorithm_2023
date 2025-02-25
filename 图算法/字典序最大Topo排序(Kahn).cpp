#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005]; // 图的邻接表
int indegree[100005];      // 记录各点的入度
priority_queue<int> q;     // 维护入度为0的大顶堆
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, i, m;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ++indegree[v];
    }
    for (i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        cout << v << " ";
        for (i = 0; i < graph[v].size(); i++)
        {
            --indegree[graph[v][i]];
            if (indegree[graph[v][i]] == 0)
                q.push(graph[v][i]);
        }
    }
    return 0;
}