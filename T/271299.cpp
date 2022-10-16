#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int inf = 1e6 + 5;

int n, ans[inf], cnt;

vector <int> adj[inf];

void dfs (int u, int f)
{
    for (int i = 0; i < adj[u].size(); i ++)
    {
        int v = adj[u][i];
        if (v == f) continue;
        dfs (v, u);
    }
    ans[u] = ++ cnt;
}

int main ()
{
    scanf ("%d", &n);
    int u, v;
    for (int i = 1; i < n; i ++)
    {
        scanf ("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs (1, 0);
    for (int i = 1; i <= n; i ++) printf ("%d ", ans[i]);
    return 0;
}