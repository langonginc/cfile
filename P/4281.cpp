#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <cstdlib> 
#include <set>
#include <vector> 
#include <climits>
using namespace std;
const int inf=500005;
int n, m, s, par[inf][30], head[3*inf], lg[3*inf], nn, dep[3*inf];

class Node
{
    public:
	int to, next;
    Node () {}
    Node (int to, int next) : to(to), next(next) {}
} pool[3*inf];

inline void add (int u, int v)
{
	pool[++nn] = Node (v, head[u]);
	head[u] = nn;
}

void dfs (int r, int f)
{
	dep[r] = dep[f] + 1;
	par[r][0] = f;
	for (int i = 1; (1 << i) <= dep[r]; i ++)
    {
		par[r][i] = par[par[r][i-1]][i-1];
	}
	for (int i = head[r]; i; i = pool[i].next)
    {
		if (pool[i].to != f)
        {
			dfs (pool[i].to, r);
		}
	}
}

int lca (int x, int y){
	if (dep[x] < dep[y])
    {
		swap (x, y);
	}
	while (dep[x] > dep[y])
    {
		x = par[x][lg[dep[x] - dep[y]] - 1];
	}
	if (x == y) return x;
	for (int i = lg[dep[x]]; i >= 0; i --)
    {
		if (par[x][i] != par[y][i])
        {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int main()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1;i < n; i ++)
    {
		int a, b;
		scanf ("%d%d", &a, &b);
		add (a, b);
		add (b, a);
	}
	for(int i=1;i<=n;i++)
    {
		lg[i] = lg[i-1] + ((1 << lg[i - 1]) == i);
	}
	dfs (1, 0);
	for(int i = 0; i < m; i ++)
    {
		int a, b, c, p;
        scanf ("%d%d%d", &a, &b, &c);
        int l1 = lca (a, b);
        int l2 = lca (a, c);
        int l3 = lca (b, c);
        if (l1 == l2) p = l3;
        else if (l1 == l3) p = l2;
        else if (l2 == l3) p = l1;
        int ans = dep[a] + dep[b] + dep[c] - dep[l1] - dep[l2] - dep[l3];
        printf ("%d %d\n", p, ans);
	}
	return 0;
} 
