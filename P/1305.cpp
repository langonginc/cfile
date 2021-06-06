#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Tree
{
    private:
        int left_child, right_child;

    public:
        inline int &lc()
        {
            return left_child;
        }
        inline int &rc()
        {
            return right_child;
        }
        inline void operator()(int _lc, int _rc)
        {
            left_child = _lc, right_child = _rc;
        }
} tree[30];

int n;

void dfs (int x)
{
    if (x == (int)('*' - 'a'))
    {
        return;
    }
    printf ("%c", (char)(x + 'a'));
    dfs (tree[x].lc());
    dfs (tree[x].rc());
}

int main ()
{
    cin >> n;
    char self1, lc1, rc1;
    cin >> self1 >> lc1 >> rc1;
    tree[(int)(self1 - 'a')]((int)(lc1 - 'a'), (int)(rc1 - 'a'));
    for (int i = 2; i <= n; i ++)
    {
        char self, lc, rc;
        cin >> self >> lc >> rc;
        tree[(int)(self - 'a')]((int)(lc - 'a'), (int)(rc - 'a'));
    }
    dfs ((int)(self1-'a'));
    return 0;
}