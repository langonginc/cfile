#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;

class Tree
{
    public:
    int lc, rc, sum;
    ll id;
} tree[maxn << 1];

int n, m, q, cnt;
int offset[maxn], rt[maxn];

inline int & lc (int p)
{
    return tree[p].lc;
}

inline int & rc (int p)
{
    return tree[p].rc;
}

inline int queryLen (int l, int r, int bound)
{
    if (r <= bound)
    {
        return r - l + 1;
    }
    else if (l <= bound)
    {
        return bound - l + 1;
    }
    else return 0;
}

void insert (int *p, int l, int r, bool type, ll id, int pos)
{
    if (*p == 0)
    {
        *p = ++ cnt;
        tree[*p].sum = queryLen (l, r, type ? n : m - 1);
    }
    tree[*p].sum ++;
    if (l == r)
    {
        tree[*p].id = id;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        insert (&lc (*p), l, mid, type, id, pos);
    }
    else
    {
        insert (&rc (*p), mid + 1, r, type, id, pos);
    }
}

ll query (int *p, int l, int r, bool type, int row, int pos)
{
    if (*p == 0)
    {
        *p = ++ cnt;
        tree[*p].sum = queryLen (l, r, type ? n : m - 1);
        if (l == r)
        {
            if (type)
            {
                tree[*p].id = 1ll * l * m;
            }
            else
            {
                tree[*p].id = 1ll * (row - 1) * m + l;
            }
        }
    }
    tree[*rt].sum --;
    if (l == r)
    {
        return tree[*p].id;
    }

    int mid = (l + r) >> 1;
    int lsum = lc (*p) ? tree[lc (*p)].sum : queryLen (l, mid, type ? n : m - 1);
    if (lsum >= pos)
    {
        return query (&lc (*p), l, mid, type, row, pos);
    }
    else
    {
        return query (&rc (*p), mid + 1, r, type, row, pos - lsum);
    }
}

int main ()
{
    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        if (y == m)
        {
            ll id = query (&rt[n + 1], 1, n - 1 + q, true, n + 1, x);
            offset[n + 1] ++;
            insert (&rt[n + 1], 1, n - 1 + q, true, id, n + offset[n + 1]);
            printf ("%lld\n", id);
        }
        else
        {
            ll id = query (&rt[x], 1, m - 1 + q, false, x, y);
            ll idLastLine = query (&rt[n + 1], 1, n - 1 + q, true, n + 1, x);
            offset[x] ++;
            insert (&rt[x], 1, m - 1 + q, false, idLastLine, m - 1 + offset[x]);
            offset[n + 1] ++;
            insert (&rt[n + 1], 1, n - 1 + q, true, id, n + offset[n + 1]);
            printf ("%lld\n", id);
        }
    }
    return 0;
}