#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 2e5 + 5;

class Edge
{
    public:
    int v, next;
    Edge () {}
    Edge (int v, int next) : v (v), next (next) {}
};

Edge pool[2 * inf];
int n, m, a[inf], sum[inf * 4], tag[inf * 4];
int head[inf], pre[inf], sz[inf], id[inf], w[inf], nn, timePoints;

inline void addEdge (int u, int v)
{
    pool[++ nn] = Edge (v, head[u]);
    head[u] = nn;
}

int dfsInit (int u, int f)
{
    pre[u] = ++ timePoints;
    id[timePoints] = u;
    sz[u] = 1;
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].v;
        if (v != f)
        {
            sz[u] += dfsInit (v, u);
        }
    }
    return sz[u];
}

inline int lc (int p){
	return p << 1;
}

inline int rc (int p){
	return p << 1 | 1;
}

void movetag (int p, int l, int r, int f){
	sum[p] += f * (r - l + 1);
	tag[p] += f;
}

void pushup (int p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
}

void pushdown (int p, int l, int r){
	int mid = (l + r) >> 1;
	movetag (lc (p), l, mid, tag[p]);
	movetag (rc (p), mid + 1, r, tag[p]);
	tag[p] = 0;
}

void update (int p, int l, int r, int ql, int qr, int d){
	if (ql <= l && r <= qr){
		sum[p] += d * (r - l + 1);
		tag[p] += d;
		return;
	}
	pushdown (p, l, r);
	int mid = (l + r) >> 1;
	if (ql <= mid){
		update (lc (p), l, mid, ql, qr, d);
	}
	if (mid < qr){
		update (rc (p), mid + 1, r, ql, qr, d);
	}
	pushup (p);
}

void build (int p, int l, int r){
	if (l == r){
		sum[p] = a[id[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}

int query (int p, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr)
    return sum[p];
	pushdown (p, l, r);
	int mid = (l + r) >> 1, result = 0;
	if (ql <= mid){
		result += query (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += query (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        addEdge (u, v), addEdge (v, u);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    dfsInit (1, 0);
    build (1, 1, n);
    while (m --)
    {
        int op, x, y;
        scanf ("%d", &op);
        if (op == 1)
        {
            scanf ("%d%d", &x, &y);
            update (1, 1, n, pre[x], pre[x] + sz[x] - 1, y);
        }
        else
        {
            scanf ("%d", &x);
            printf ("%d\n", query (1, 1, n, pre[x], pre[x] + sz[x] - 1));
        }
    }
    return 0;
}