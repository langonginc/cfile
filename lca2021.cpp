#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 500005;
class Node
{
    public:
    int to, next;
} pool[4 * inf];
int n, m, head[inf], par[inf][30], dep[inf], lg[inf], nn;

void add (int u, int v)
{
    pool[++ nn].to = v;
    pool[nn].next = head[u];
    head[u] = nn;
}

void dfs (int u, int f)
{
    par[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; (1 << i) <= dep[u]; i ++)
    {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (v != f)
        {
            dfs (v, u);
        }
    }
}

int lca (int x, int y)
{
    if (dep[x] < dep[y]) swap (x, y);
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
    int s;
	scanf ("%d%d%d", &n,&m,&s);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
    for (int i = 1; i <= n; i ++)
    {
        lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
    }
    dfs (s, 0);
    for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y)); 
	}
    return 0;
}