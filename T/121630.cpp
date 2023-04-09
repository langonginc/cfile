#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 100005;

vector <int> adj[inf];
int vis[inf], flag, but[inf];

// void dfs (int u, int f)
// {
//     for (int i = 0; i < adj[u].size (); i ++)
//     {
//         int v = adj[u][i];
//         if (flag) return;
//         if (v != f)
//         {
//             if (vis[v])
//             {
//                 flag = true;
//                 return;
//             }
//             vis[v] = 1;
//             dfs (v, u);
//             vis[v] = 0;
//             if (flag) return;
//         }
//     }
// }

// int main ()
// {
//     int u, v, w, m, s;
//     scanf ("%d%d%d", &u, &v, &w);
//     while (u != -1 && v != -1 && w != -1)
//     {
//         for (int i = 0; i < inf; i ++) adj[i].clear ();
//         memset (vis, 0, sizeof (vis));
//         m = 0, flag = 0;
//         s = u;
//         while (u != 0 && v != 0 && w != 0)
//         {
//             adj[u].push_back (v), adj[v].push_back (u);
//             scanf ("%d%d%d", &u, &v, &w);
//         }
//         vis[s] = 1;
//         dfs (s, 0);
//         if (flag) printf ("No\n");
//         else printf ("Yes\n");
//         scanf ("%d%d%d", &u, &v, &w);
//     }
// }

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100001
// vector<int> adj[MAX];
bool visited[MAX];
bool isCyclic(int u, int parent)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            if (isCyclic(v, u))
                return true;
        }
        else if (v != parent)
            return true;
    }
    return false;
}
bool isTree(int n, int s)
{
    memset(visited, false, sizeof (visited));
    if (isCyclic(s, -1))
        return false;
    // for (int i = 1; i <= n; i++)
    //     if (!visited[i])
    //         return false;
    return true;
}
int main()
{
    int u, v, w, m, s, n;
    scanf ("%d%d%d", &u, &v, &w);
    while (u != -1 && v != -1 && w != -1)
    {
        for (int i = 0; i < inf; i ++) adj[i].clear ();
        memset (vis, 0, sizeof (vis));
        memset (but, 0, sizeof (but));
        m = 0, flag = 0, n = 0;
        s = u;
        while (u != 0 && v != 0 && w != 0)
        {
            if (!but[u]) but[u] = true, n ++;
            if (!but[v]) but[v] = true, n ++;
            adj[u].push_back (v), adj[v].push_back (u);
            m ++;
            scanf ("%d%d%d", &u, &v, &w);
        }
        if (isTree(n, s) && m == n - 1)
            cout << "Yes\n";
        else
            cout << "No\n";
        scanf ("%d%d%d", &u, &v, &w);
    }
    return 0;
}