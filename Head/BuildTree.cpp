#include <iostream>
#include <cstring>
using namespace std;
char tree[1005];
// char s[1005];

void buildTree (int x)
{
    cin >> tree[x];
    // if (tree[x] == '\0')
    // {
    //     return;
    // }
    if (tree[x] != '#')
    {
        buildTree (2 * x);
        buildTree (2 * x + 1);
    }
}

int main ()
{
    memset (tree, '#', sizeof (tree));
    buildTree (1);
    for (int i = 1; i <= 50; i ++)
    {
        cout << tree[i];
    }
    return 0;
}