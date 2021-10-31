#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
class Number
{
    public:
    int num, id;
    Number () {}
    Number (int num, int id) : num(num), id(id) {}
} a[1000005];

int n, m;
deque <Number> q;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        int num;
        scanf ("%d", &num);
        a[i] = Number (num, i);
    }
    for (int i = 1; i <= n; i ++)
    {
        while (!q.empty() && q.back().num >= a[i].num)
        {
            q.pop_back();
        }
        q.push_back(a[i]);
        if (q.front().id == i - m)
        {
            q.pop_front();
        }
        if (i >= m)
        {
            printf ("%d\n", q.front().num);
        }
    }
    return 0;
}