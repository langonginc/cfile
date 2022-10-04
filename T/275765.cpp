#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 5005;

ll n, dp[4][inf], fi[inf], size[4][inf];

/*
0 -> No delete
1 -> delete left
2 -> delete right
3 -> both delete
*/

vector <int> adj[inf];

void dfs1 (int u, int f)
{
    size[u] = 1;
    for (int i = 0; i < adj[u].size (); i ++)
    {
        if (i == f) continue;
        dfs1 (i, u);
        for (int j = 0; j < 4; j ++)
        size[j][u] += size[j][i];
    }
}

void dfs2 (int u, int f)
{
    // dp[u] = fi[size[u]];
    for (int i = 0; i < adj[u].size (); i ++)
    {
        if (i == f) continue;
        dfs2 (i, u);
        // dp[u] <= min (dp[u], dp[i]);
        if ()
    }
}

int main ()
{
    scanf ("%lld", &n);
    for (int i = 2; i <= n; i ++)
    {
        scanf ("%lld", &fi[i]);
    }
    fi[1] = LLONG_MAX;
    int u, v;
    for (int i = 1; i < n; i ++)
    {
        scanf ("%d%d", &u, &v);
        adj[u].push_back (v);
        adj[v].push_back (u);
    }
    dfs1 (1, 0);
    dfs2 (1, 0);
    printf ("%lld\n", dp[1]);
    return 0;
}