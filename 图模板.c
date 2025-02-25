#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10005
const int INF = 2147483646;
int visited[MAXN];
int distance[MAXN];
int queue[MAXN];
int front = 0, cnt = 0, rear = -1;
int isEmpty()
{
    return cnt == 0;
}
void enQueue(int queue[], int item)
{
    queue[++rear] = item;
    cnt++;
}
int deQueue(int queue[])
{
    int e = queue[front];
    cnt--;
    front++;
    return e;
}
typedef struct edge // 边
{
    int adj;
    int weight;
    struct edge *link;
} Edgeptr;
typedef struct ver // 顶点
{
    Edgeptr *link;
} Verptr;
Verptr graph[10005]; // 是.link 不是->link 不带*！

Edgeptr *insertEdge(Edgeptr *head, int adj)
{
    Edgeptr *p = NULL, *q = NULL, *r = NULL;
    p = (Edgeptr *)malloc(sizeof(Edgeptr));
    p->adj = adj;
    p->link = NULL; // 建立边链节
    if (head == NULL)
    {
        head = p;
        return head;
    }
    if (head->adj > adj)
    { // 第一个邻接点就比p的序号大
        p->link = head;
        head = p;
    }
    else
    {
        for (q = r = head; q != NULL && q->adj < adj; r = q, q = q->link)
            ; // r为q的前驱，此步r后面是应当插入的地方,保证链表按升序排列
        p->link = r->link;
        r->link = p; // 将p插入r后面、q前面
    }
    return head;
} // 可以保证访问时编号从小到大
void *deleteEdge(int verNum, int fuck) // 删除入度为fuck的边，阻断了各点通向fuck的路，但没阻断fuck通向各点的路
{
    Edgeptr *p = NULL, *q = NULL;
    for (int i = 0; i < verNum; i++)
    {
        if (graph[i].link->adj == fuck) // 第一个边就是fuck
        {
            graph[i].link = graph[i].link->link;
        }
        else
        {
            for (q = p = graph[i].link; p != NULL; q = p, p = p->link)
                if (p->adj == fuck)
                    q->link = p->link;
        }
    }
}
void DFS(Verptr graph[], int v)
{
    Edgeptr *p;
    visited[v] = 1;
    printf("%d ", v);
    for (p = graph[v].link; p != NULL; p = p->link)
    {
        if (!visited[p->adj])
            DFS(graph, p->adj);
    }
}
void BFS(Verptr graph[], int v)
{
    for (int i = 0; i < MAXN - 1; i++)
    {
        distance[i] = INF;
    }
    Edgeptr *p = NULL;
    visited[v] = 1; // 标识最头顶点入队
    distance[v] = 0;
    enQueue(queue, v); // 当前节点元素入队
    while (!isEmpty(queue))
    {
        v = deQueue(queue);
        printf("%d ", v);
        for (p = graph[v].link; p != NULL; p = p->link)
        {
            if (!visited[p->adj])
            {
                visited[p->adj] = 1; // 标识某顶点入队
                distance[p->adj] = distance[v] + 1;
                enQueue(queue, p->adj);
            }
        }
    }
}
int main()
{

    return 0;
}