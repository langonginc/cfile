#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int inf = 105;

class Edge
{
    public:
    int v, w;
    Edge () {}
    Edge (int _v, int _w) { v = _v, w = _w; }
};

vector <Edge> adj[inf];
queue <int> q;
int n, m, c[inf], deg[inf];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        int u;
        scanf ("%d%d", &c[i], &u);
        if (c[i])
        {
            q.push (i);
        }
        else
        {
            c[i] -= u;
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);
        adj[u].push_back (Edge (v, w));
        deg[v] ++;
    }
    while (! q.empty ())
    {
        int u = q.front ();
        q.pop ();
        if (c[u] <= 0)
        {
            for (int i = 0; i < adj[u].size (); i ++)
            {
                int v = adj[u][i].v;
                if (-- deg[v] == 0)
                {
                    q.push (v);
                }
            }
        }
        else
        {
            for (int i = 0; i < adj[u].size (); i ++)
            {
                int v = adj[u][i].v, w = adj[u][i].w;
                c[v] += c[u] * w;
                if (-- deg[v] == 0)
                {
                    q.push (v);
                }
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i ++)
    {
        if (adj[i].size () == 0 && c[i] > 0)
        {
            printf ("%d %d\n", i, c[i]);
            flag = false;
        }
    }
    if (flag) printf ("NULL\n");
    return 0;
}
