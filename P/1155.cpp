#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int inf = 100005;

class Node
{
    public:
    int to, next;
    Node () {}
    Node (int _to, int _next)
    {
        to = _to, next = _next;
    }
};

int n, m, head[inf], nn;
Node pool[inf];

int col[inf], ans;
int a[inf], pre[inf];

void addEdge (int u, int v)
{
    pool[++ nn] = Node (v, head[u]);
    head[u] = nn;
}

bool dfs (int u, int cid)
{
    col[u] = cid;
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (col[v] != -1 && col[v] == col[u])
        {
            return false;
        }
        if (col[v] == -1 && dfs (v, cid ^ 1) == false)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    scanf ("%d", &n);
    memset (pre, 0x7f, sizeof (pre));
    memset (col, 0xff, sizeof (col));
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    for (int i = n; i > 0; i --)
    {
        pre[i] = min (pre[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            if (a[i] < a[j] && pre[j + 1] < a[i])
            {
                addEdge (i, j), addEdge (j, i);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        if (col[i] == -1)
        {
            if (dfs (i, 0) == false)
            {
                printf ("0\n");
                return 0;
            }
        }
    }
    stack <int> s1, s2;
    int index = 1, num = 1;
    while (num <= n)
    {
        while (! s1.empty () && s1.top () == num)
        {
            s1.pop ();
            printf ("b ");
            num ++;
        }
        while (! s2.empty () && s2.top () == num)
        {
            s2.pop ();
            printf ("d ");
            num ++;
        }
        if (col[index] == 0)
        {
            printf ("a ");
            s1.push (a[index ++]);
        }
        else if (col[index] == 1)
        {
            printf ("c ");
            s2.push (a[index ++]);
        }
    }
    return 0;
}