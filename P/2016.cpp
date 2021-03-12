#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;
const int inf = 15000;

int dp[inf][2]; //0: Put, 1: Don't Put
vector <int> adj[inf];
int n;

void dfs (int u, int f)
{
    dp[u][1] = 1,
    dp[u][0] = 0;
    for (int i = 0; i < adj[u].size(); i ++)
    {
        if (adj[u][i] != f)
        {
            dfs (adj[u][i], u);
            dp[u][0] += dp[adj[u][i]][1];
            dp[u][1] += min (dp[adj[u][i]][1], dp[adj[u][i]][0]);
        }
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        int x, k, g;
        scanf ("%d%d", &x, &k);
        for (int i = 0; i < k; i ++)
        {
            scanf ("%d", &g);
            adj[x].push_back(g);
        }
    }
    dfs (0, INT_MAX);
    printf ("%d\n", min(dp[0][0], dp[0][1]));
    return 0;
}
