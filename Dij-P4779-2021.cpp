#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int inf = 2e5 + 5;

class Edge
{
    public:
    int v, w;
    Edge (int v, int w) : v (v), w (w) {}
};

class Node
{
    public:
    int v, w;
    Node (int v, int w) : v (v), w (w) {}
    bool operator < (const Node &t) const
    {
        return w > t.w;
    }
};

int n, m, s, dis[inf], vis[inf];
vector <Edge> adj[inf];
priority_queue <Node> q;

int main ()
{
    scanf ("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i ++)
    {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        adj[a].push_back (Edge (b, c));
    }
    memset (dis, 0x3f, sizeof(dis));
    q.push (Node (s, 0));
    dis[s] = 0;
    while (!q.empty())
    {
        Node e = q.top ();
        q.pop ();
        if (vis[e.v]) continue;
        vis[e.v] = true;
        for (int i = 0; i < adj[e.v].size (); i ++)
        {
            if (dis[e.v] + adj[e.v][i].w < dis[adj[e.v][i].v])
            {
                dis[adj[e.v][i].v] = dis[e.v] + adj[e.v][i].w;
                q.push (Node (adj[e.v][i].v, dis[adj[e.v][i].v]));
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d ", dis[i]);
    }
    return 0;
}
