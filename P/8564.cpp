#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 5005;

ll n, dp[inf][inf], fi[inf], size[inf];

vector <int> adj[inf];

void dfs1 (int u, int f)
{
    size[u] = 1;
    for (int i = 0; i < adj[u].size (); i ++)
    {
        int v = adj[u][i];
        if (v == f) continue;
        dfs1 (v, u);
        size[u] += size[v];
    }
}

void dfs2 (int u, int f)
{
    // printf ("%d,%d\n", u, f);
    int sonnum = 0, tmp;
    for (int i = 0; i < adj[u].size (); i ++)
    {
        int v = adj[u][i];
        if (v == f) continue;
        dfs2 (v, u);
        sonnum ++;
        for (int j = size[v]; j >= 1; j --)
        {
            for (int k = max (1, j - sonnum); k <= j && k < size[v]; k ++)
            {
                // 删除 j 个人，有 k 个在这个儿子这里删除
                dp[u][j] = min (dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
        // for (int j = size[u]; j >= 1; j --)
        // {
        //     for (int k = 1; k <= j; k ++)
        //     {
        //         // 删除 j 个人，有 k 个在这个儿子这里删除
        //         dp[u][j] = min (dp[u][j], dp[u][j - k] + dp[v][k]);
        //     }
        // }
    }


    // * 删儿子
    if (u == 1) tmp = adj[u].size ();
    else tmp = adj[u].size () - 1;
    // printf ("@%lld\n", size[u] - adj[u].size () - 1 + tmp);
    for (int i = 0; i <= size[u] - tmp - 1; i ++)
    {
            // printf ("Sec\n");
        dp[u][size[u] - 1] = min (dp[u][size[u] - 1], dp[u][i] + fi[size[u] - i]);
    }
    // printf ("-> %d,%d\n", u, f);
}

int main ()
{
    scanf ("%lld", &n);
    for (int i = 2; i <= n; i ++)
    {
        scanf ("%lld", &fi[i]);
    }
    int u, v;
    for (int i = 1; i < n; i ++)
    {
        scanf ("%d%d", &u, &v);
        adj[u].push_back (v);
        adj[v].push_back (u);
    }
    memset (dp, 0x7f, sizeof (dp));
    dfs1 (1, 0);
    dfs2 (1, 0);
    printf ("%lld\n", dp[1][size[1] - 1]);
    return 0;
}