#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
const int inf = 1005;

int n, x;
vector <int> adj[inf];

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            scanf ("%d", &x);
            if (x)
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d ", adj[i].size());
        for (int j = 0; j < adj[i].size(); j ++)
        {
            printf ("%d ", adj[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
