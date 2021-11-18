#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int inf = 2e5 + 5;

class Edge
{
    public:
    int to, next;
    Edge () {}
    Edge (int to, int next): to(to), next(next) {}
};

class UnDire
{
    public:
    int u, v;
    UnDire () {}
    UnDire (int u, int v): u(u), v(v) {}
};

queue <int> q;
Edge pool[inf];
UnDire s[inf];
int t, n, m, head[inf], nn, indeg[inf], topu[inf], scnt;

inline void addEdge (int u, int v)
{
    pool[++ nn] = Edge (v, head[u]);
    head[u] = nn;
    indeg[v] ++;
}

bool sort ()
{
    int sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (!indeg[i])
        {
            q.push (i);
        }
    }
    while (!q.empty ())
    {
        int u = q.front ();
        q.pop ();
        topu[u] = ++ sum;
        for (int i = head[u]; i; i = pool[i].next)
        {
            indeg[pool[i].to] --;
            if (indeg[pool[i].to] == 0)
            {
                q.push (pool[i].to);
            }
        }
    }
    return sum == n;
}

int main ()
{
    scanf ("%d", &t);
    while (t --)
    {
        nn = scnt = 0;
        memset (head, 0, sizeof (head));
        memset (indeg, 0, sizeof (indeg));
        memset (topu, 0x3f, sizeof (topu));
        while (!q.empty ()) q.pop();
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++)
        {
            int type, a, b;
            scanf ("%d%d%d", &type, &a, &b);
            if (type) addEdge (a, b);
            else s[++ scnt] = UnDire (a, b);
        }
        if (sort ())
        {
            printf ("YES\n");
            for (int u = 1; u <= n; u ++)
            {
                for (int i = head[u]; i; i = pool[i].next)
                {
                    printf ("%d %d\n", u, pool[i].to);
                }
            }
            for (int i = 1; i <= scnt; i ++)
            {
                if (topu[s[i].u] > topu[s[i].v])
                {
                    printf ("%d %d\n", s[i].v, s[i].u);
                }
                else printf ("%d %d\n", s[i].u, s[i].v);
            }
        }
        else printf ("NO\n");
    }
    return 0;
}