#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 2e5 + 5;

class Node
{
    public:
    int u, v, w;
    Node () {}
    Node (int u, int v, int w) : u (u), v (v), w (w) {}
    bool operator < (const Node &t) const
    {
        return w < t.w;
    }
};

int n, m, f[inf], cnt, ans;
Node node[inf];

int find (int x)
{
    if (f[x] == x)
    {
        return x;
    }
    return f[x] = find(f[x]);
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);
        node[i] = Node (u, v, w);
    }
    for (int i = 1; i <= n; i ++) f[i] = i;
    sort (node + 1, node + m + 1);
    for (int i = 1; i <= m && cnt < n - 1; i ++)
    {
        if (find (node[i]. u) != find (node[i].v))
        {
            f[find(node[i]. u)] = find(node[i].v);
            cnt ++;
            ans += node[i].w;
        }
    }
    if (cnt == n - 1) printf ("%d\n", ans);
    else printf ("orz\n");
    return 0;
}