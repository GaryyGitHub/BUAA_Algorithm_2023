#include <bits/stdc++.h>
using namespace std;
#define MAXN 10006
const int INF = 2147483646;
vector<pair<int, int>> graph[MAXN]; // 数对，存储相邻定点和边的权重weight
struct
{
    int u, v, weight;
} edge[MAXN]; // 边数组
int disBFS[MAXN];
int disDFS[MAXN][2], timee;   // 0-d-发现时间, 1-f-完成时间,
int piBFS[MAXN], piDFS[MAXN]; // 最短路径的前驱结点
int disBF[MAXN], piBF[MAXN];  // BellmanFord
int wei[1005][1005];          // 各条边的权值，但内存不一定够，需改进！
// maybe 可以
vector<int> topo; // 存储拓扑排序后的结果
queue<int> q;
int verNum; // 顶点个数
int edgeNum;
void insertEdge(int head, int v, int weight)
{
    graph[head].push_back({v, weight});
    edge[edgeNum].u = head, edge[edgeNum].v = v, edge[edgeNum].weight = weight;
    edgeNum++;
    wei[head][v] = weight; // 不好！！！相当于邻接矩阵
}
void deleteEdge(int v)
{
    for (int i = 0; i < verNum; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (v == graph[i][j].first)
            {
                graph[i].erase(graph[i].begin() + j);
                verNum--;
            }
        }
    }
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
            if (disBFS[graph[u][j].first] == INF)
            {
                disBFS[graph[u][j].first] = disBFS[u] + 1;
                piBFS[graph[u][j].first] = u;
                q.push(graph[u][j].first);
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
        if (disDFS[graph[u][i].first][0] == INF)
        {
            piDFS[graph[u][i].first] = u;
            DFSVISIT(graph[u][i].first);
        }
    }
    timee++;
    disDFS[u][1] = timee;
    topo.insert(topo.begin(), u); // 为了拓扑排序，完成晚的排前面，慎用insert！！！1e5时会TLE
    // topo.push_back(u);//推荐用pushback
}
void DFS()
{
    int i;
    for (i = 1; i <= verNum; i++)
    {
        disDFS[i][0] = disDFS[i][1] = INF;
        piDFS[i] = -1;
    }
    timee = 0; // initialize
    for (i = 1; i <= verNum; i++)
    {
        if (disDFS[i][0] == INF)
            DFSVISIT(i);
    }
}
void INIT(int s)
{
    for (int i = 0; i <= verNum; i++)
    {
        disBF[i] = INF;
        piBF[i] = -1;
    }
    disBF[s] = 0;
}
void RELAX_UVW(int u, int v, int w)
{
    if (disBF[v] > disBF[u] + w)
    {
        disBF[v] = disBF[u] + w;
        piBF[v] = u;
    }
}
void RELAX(int EDGE)
{
    if (disBF[edge[EDGE].v] > disBF[edge[EDGE].u] + wei[edge[EDGE].u][edge[EDGE].v])
    {
        disBF[edge[EDGE].v] = disBF[edge[EDGE].u] + wei[edge[EDGE].u][edge[EDGE].v];
        piBF[edge[EDGE].v] = edge[EDGE].u;
    }
}
bool BELLMAN(int s)
{
    INIT(s);
    for (int i = 1; i <= verNum - 1; i++)
        for (int j = 0; j < edgeNum; j++)
            RELAX(j); // 对edge结构体中的第j个边relax
                      // 若要用UVW形式，RELAX_UVW(edge[j].u,edge[j].v,edge[j].weight);
    for (int j = 0; j < edgeNum; j++)
        if (disBF[edge[j].v] > disBF[edge[j].u] + edge[j].weight)
            return false;
    return true;
}
void TOPOBELLMAN(int s)
{
    DFS();
    INIT(s);
    for (auto u : topo)
    {
        for (auto v : graph[u])
        {
            RELAX_UVW(u, v.first, v.second);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // bellman
    insertEdge(1, 2, 6);
    insertEdge(1, 4, 7);
    insertEdge(2, 4, 8);
    insertEdge(2, 3, 5);
    insertEdge(2, 5, -4);
    insertEdge(3, 2, -2);
    insertEdge(4, 3, -3);
    insertEdge(4, 5, 9);
    insertEdge(5, 1, 2);
    insertEdge(5, 3, 7);
    verNum = 5; // ready to cin

    // deleteEdge(2);

    // for (auto e : graph[1])
    //     cout << e;

    // BFS(1);
    // cout << verNum << '\n';
    // for (int i = 1; i <= verNum; i++)
    //     cout << disBFS[i] << " ";
    // cout << '\n';
    // for (int i = 1; i <= verNum; i++)
    //     cout << piBFS[i] << " ";

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

    // BELLMAN(1);

    TOPOBELLMAN(1);
    for (int i = 1; i <= verNum; i++)
        cout << disBF[i] << " ";
    cout << '\n';
    for (int i = 1; i <= verNum; i++)
        cout << piBF[i] << " "; // 三种单元最短路径算法共用一种输出
    return 0;
}