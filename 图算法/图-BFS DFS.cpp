#include <bits/stdc++.h>
using namespace std;
#define MAXN 10006
const int INF = 2147483646;
vector<int> graph[MAXN]; // vector邻接表存矩阵点
int disBFS[MAXN];
int disDFS[MAXN][2], timee;   // 0-d-发现时间, 1-f-完成时间,
int piBFS[MAXN], piDFS[MAXN]; // 最短路径的前驱结点
vector<int> topo;             // 存储拓扑排序后的结果
queue<int> q;
int verNum; // 顶点个数
void insertEdge(int head, int v)
{ // 加边操作
    graph[head].push_back(v);
}
void BFS(int s) // 适用于无权重图求最短路径
{
    int i, j;
    for (i = 1; i <= verNum; i++) // 此处应为图编号最大数，假设从1开始
    {
        disBFS[i] = INF;
        piBFS[i] = -1;
    }
    disBFS[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (j = 0; j < graph[u].size(); j++)
        {
            if (disBFS[graph[u][j]] == INF)
            {
                disBFS[graph[u][j]] = disBFS[u] + 1;
                piBFS[graph[u][j]] = u;
                q.push(graph[u][j]);
            }
        }
    }
}
void DFSVISIT(int u)
{
    timee++;
    disDFS[u][0] = timee; // u.d=time
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (disDFS[graph[u][i]][0] == INF)
        {
            piDFS[graph[u][i]] = u;
            DFSVISIT(graph[u][i]);
        }
    }
    timee++;
    disDFS[u][1] = timee;
    topo.insert(topo.begin(), u); // 为了拓扑排序
}
void DFS()
{
    int i;
    for (i = 1; i <= verNum; i++)
    {
        disDFS[i][0] = disDFS[i][1] = INF;
        piDFS[i] = -1;
    }
    timee = 0;
    for (i = 1; i <= verNum; i++)
    {
        if (disDFS[i][0] == INF)
            DFSVISIT(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    insertEdge(1, 2);
    insertEdge(1, 4);
    insertEdge(4, 2);
    insertEdge(2, 5);
    insertEdge(5, 4);
    insertEdge(3, 5);
    insertEdge(3, 6);
    verNum = 6; // ready to cin
    // deleteEdge(2);
    // for (auto e : graph[1])
    // {
    //     cout << e;
    // }
    BFS(1);
    cout << verNum << '\n';
    for (int i = 1; i <= verNum; i++)
        cout << disBFS[i] << " ";
    cout << '\n';
    for (int i = 1; i <= 5; i++)
        cout << piBFS[i] << " ";
    // DFS();
    // for (int i = 1; i <= verNum; i++)
    //     cout << disDFS[i][0] << " ";
    // cout << '\n';
    // for (int i = 1; i <= verNum; i++)
    //     cout << disDFS[i][1] << " ";
    // cout << '\n';
    // for (int i = 1; i <= verNum; i++)
    //     cout << piDFS[i] << " ";
    // cout << '\n';
    // for (auto e : topo)
    //     cout << e << " ";
    return 0;
}