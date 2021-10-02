#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 255;
class Node 
{
    public:
    int num, pos;
    void operator () (int _num, int _pos)
    {
        num = _num;
        pos = _pos;
    }
};
bool cmp1 (Node & a, Node & b)
{
    if (a.num == b.num)
        return a.pos > b.pos;
    return a.num < b.num;
}
bool cmp2 (Node & a, Node & b)
{
    if (a.pos == b.pos)
        return a.num < b.num;
    return a.pos < b.pos;
}
Node a[inf];
int len, k;
int main ()
{
    string ch;
    cin >> ch;
    cin >> k;
    len = ch.length();
    for (int i = 1; i <= len; i ++)
    {
        a[i](ch[i - 1] - '0', i);
    }
    sort (a + 1, a + len + 1, cmp1);
    sort (a + 1, a + len + 1 - k, cmp2);
    for (int i = 1; i <= len - k; i ++)
    {
        printf ("%d", a[i]);
    }
    return 0;
}