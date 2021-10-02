#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 55;
vector <int> adj[inf];
int n, m, vis[inf], ans;

void dfs (int u, int f, int cnt)
{
    if (cnt >= n)
    {
        ans ++;
        return;
    }
    for (int i = 0; i < adj[u].size(); i ++)
    {
        if (adj[u][i] != f && !vis[adj[u][i]])
        {
            vis[adj[u][i]] = 1;
            dfs (adj[u][i], u, cnt + 1);
            vis[adj[u][i]] = 0;
        }
    }
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[1] = 1;
    dfs (1, 0, 1);
    printf ("%d", ans);
    return 0;
}