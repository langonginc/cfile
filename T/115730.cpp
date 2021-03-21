#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
const int inf = 200005;

class Edge
{
public:
    int v, w;
};

Edge edge (int v, int w)
{
    Edge x;
    x.v = v, x.w = w;
    return x;
}

int n, m;
vector <Edge> adj[inf];
vector <Edge> adj2[inf];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);
        adj[u].push_back(edge(v, w));
        adj2[v].push_back(edge(u, w));
    }
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d ", adj[i].size());
    }
    printf ("\n");
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d ", adj2[i].size());
    }
    return 0;
}
