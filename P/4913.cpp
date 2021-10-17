#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e6 + 5;

class Node
{
    public:
    int left, right;
} node[inf];

int n;

int dfs (int x, int dep)
{
    if (x == 0) return 0;
    return max (dep, max (dfs (node[x].left, dep + 1), dfs (node[x].right, dep + 1)));
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {

        scanf ("%d%d", &node[i].left, &node[i].right);
    }
    printf ("%d\n", dfs(1, 1));
    return 0;
}
