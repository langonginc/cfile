#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf = 1000005;

class Node
{
    public:
        Node (int _v, int _w)
        {
            v = _v, w = _w;
        }
        Node () {}
        int v, w;
        bool operator < (const Node &tmp) const
        {
            return w > tmp.w;
        }
};

class Edge
{
    public:
        Edge (int _to, int _next)
        {
            to = _to, next = _next;
        }
        Edge () {}
        int to, next;
};

int n, m, head[inf], cnt, dis[inf][2];
bool vis[inf][2];
Edge edge[inf];
priority_queue <Node> q;

void addEdge(int u, int v)
{
    edge[++ cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

void dijkstra ()
{
    memset (dis, 0x3f, sizeof (dis));
    q.push (Node (1, 0));
    dis[1][0] = 0;
    while (!q.empty ())
    {
        Node tmp = q.top();
        q.pop();
        for (int i = head[tmp.v]; i != 0; i = edge[i].next)
        {
            if (dis[edge[i].to][0] > dis[tmp.v][1] + 1)
            {
                dis[edge[i].to][0] = dis[tmp.v][1] + 1;
                if (!vis[edge[i].to][0])
                {
                    vis[edge[i].to][0] = true;
                    q.push (Node (edge[i].to, dis[edge[i].to][0]));
                }
            }
            if (dis[edge[i].to][1] > dis[tmp.v][0] + 1)
            {
                dis[edge[i].to][1] = dis[tmp.v][0] + 1;
                if (!vis[edge[i].to][1])
                {
                    vis[edge[i].to][1] = true;
                    q.push (Node (edge[i].to, dis[edge[i].to][1]));
                }
            }
        }
    }
}

int main ()
{
    int q;
    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        addEdge (u, v);
        addEdge (v, u);
    }
    dijkstra();
    while (q --)
    {
        int a, l;
        scanf ("%d%d", &a, &l);
        if (dis[a][l % 2] <= l && head[1])
        {
            printf ("Yes\n");
        }
        else
        {
            printf ("No\n");
        }
    }
    return 0;
}