#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 1e5 + 5;
int n, m, ans[inf];
vector <int> adj[inf];

void dfs (int u, int num)
{
    if (ans[u]) return;
    ans[u] = num;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        dfs (adj[u][i], num);
    }
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++) 
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        // adj[u].push_back (v);
        adj[v].push_back (u);
    }
    for (int i = n; i >= 1; i --)
    {
        // if (!ans[i])
        {
            dfs (i, i);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d ", ans[i]);
    }
    return 0;
}
