#include <iostream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;
const int inf = 3005;

#ifndef EDGE_CLASS
#define EDGE_CLASS

class Edge
{
	public:
		int to, next, w;
		
		void operator () (int _to, int _next, int _w)
		{
			to = _to, next = _next, w = _w;
		}
		
		Edge ();
		Edge (int _to, int _next, int _w);
};

Edge::Edge() {}
Edge::Edge(int _to, int _next, int _w)
{
	to = _to, next = _next, w = _w;
}

#endif

int n, m, dp[inf][inf], tot;
Edge *e[inf];
int head[inf];

inline void add (int x, int y, int w)
{
	e[++ tot] = new Edge(y, head[x], w);
	head[x] = tot;
}

int dfs (int u, int f)
{
	int ths = 0;
	for (int i = head[u]; i != -1; i = e[i]->next)
    {
        int v = e[i]->to;
        if (v == f) continue;
        ths += dfs (v, u) + 1;
        for (int j = min (ths,m); j >= 1; j --)
        {
        	for (int k = j - 1; k >= 0; k --)
        	{
            	dp[u][j] = max (dp[u][j], dp[u][j - k - 1] + dp[v][k] + e[i]->w);
			}
		}
    }
    return ths;
}

int main ()
{
	scanf ("%d%d", &n, &m);
	memset (head, -1, sizeof (head));
	for (int i = 1; i <= n; i ++)
	{
		int x, y;
		scanf ("%d%d", &x, &y);
		add (x, i, y);
	}
	dfs (0, 0);
	printf ("%d\n", dp[0][m]);
	return 0;
}