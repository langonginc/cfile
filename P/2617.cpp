#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

inline int lowbit (int x)
{
    return x & (-x);
}

int n, m;
int a[maxn], c[maxn];
int cnt, rt[maxn];

class Tree
{
    public:
    int lc, rc, count;
} tree[maxn << 2];

inline int &lc (int p)
{
    return tree[p].lc;
}

inline int &rc (int p)
{
    return tree[p].rc;
}

void insertTree (int *p, int l, int r, int v, int d)
{
    if (*p == 0)
    {
        *p = ++ cnt;
    }
    tree[*p].count += d;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid)
    {
        insertTree (&lc (*p), l, mid, v, d);
    }
    else
    {
        insertTree (&rc (*p), mid + 1, r, v, d);
    }
}

void insertArray (int x, int y, int d)
{
    for (int i = x; i <= n; i += lowbit (i))
    {
        insertTree (&rt[i], 1, n, y, d);
    }
}

int lcnt, rcnt, lrt[maxn], rrt[maxn];

int queryTree (int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int sum = 0;
    for (int i = 1; i <= lcnt; i ++)
    {
        sum -= tree[lc (lrt[i])].count;
    }
    for (int i = 1; i <= rcnt; i ++)
    {
        sum += tree[lc (rrt[i])].count;
    }
    int mid = (l + r) >> 1;
    if (k <= sum)
    {
        for (int i = 1; i <= lcnt; i ++)
        {
            lrt[i] = lc (lrt[i]);
        }
        for (int i = 1; i <= rcnt; i ++)
        {
            rrt[i] = lc (rrt[i]);
        }
        return queryTree (l, mid, k);
    }
    else
    {
        for (int i = 1; i <= lcnt; i ++)
        {
            lrt[i] = rc (lrt[i]);
        }
        for (int i = 1; i <= rcnt; i ++)
        {
            rrt[i] = rc (rrt[i]);
        }
        return queryTree (mid + 1, r, k - sum);
    }
}

int queryArray (int l, int r, int k)
{
    lcnt = 0, rcnt = 0;
    for (int i = l - 1; i > 0; i -= lowbit (i))
    {
        lrt[++ lcnt] = rt[i];
    }
    for (int i = r; i > 0; i -= lowbit (i))
    {
        rrt[++ rcnt] = rt[i];
    }
    return queryTree (1, 1e9, k);
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        insertArray (i, a[i], 1);
    }
    for (int i = 1; i <= m; i ++)
    {
        char t[3];
        int l, r, x, y;
        scanf ("%s", t);
        if (t[0] == 'Q')
        {
            scanf ("%d%d%d", &l, &r, &x);
            printf ("%d\n", queryArray (l, r, x));
        }
        if (t[0] == 'C')
        {
            scanf ("%d%d", &x, &y);
            insertArray (x, a[x], -1);
            a[x] = y;
            insertArray (x, y, 1);
        }
    }
}