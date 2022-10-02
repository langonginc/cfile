// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int inf = 255;
// class Node 
// {
//     public:
//     int num, pos;
//     void operator () (int _num, int _pos)
//     {
//         num = _num;
//         pos = _pos;
//     }
// };
// bool cmp1 (Node & a, Node & b)
// {
//     if (a.num == b.num)
//         return a.pos > b.pos;
//     return a.num < b.num;
// }
// bool cmp2 (Node & a, Node & b)
// {
//     if (a.pos == b.pos)
//         return a.num < b.num;
//     return a.pos < b.pos;
// }
// Node a[inf];
// int len, k;
// int main ()
// {
//     string ch;
//     cin >> ch;
//     cin >> k;
//     len = ch.length();
//     for (int i = 1; i <= len; i ++)
//     {
//         a[i](ch[i - 1] - '0', i);
//     }
//     sort (a + 1, a + len + 1, cmp1);
//     sort (a + 1, a + len + 1 - k, cmp2);
//     for (int i = 1; i <= len - k; i ++)
//     {
//         printf ("%d", a[i]);
//     }
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 255;

int num[inf];
int f[10][inf];
int ans[inf];
int main ()
{
    string s;
    cin >> s;
    int len = s.length (), k;
    cin >> k;
    for (int i = 0; i < len; i ++)
    {
        num[i + 1] = s[i] - '0';
        for (int j = 0; j <= 9; j ++)
        {
            f[j][i + 1] = f[j][i];
            if (num[i + 1] == j) f[j][i + 1] += num[i + 1];
        }
    }
    for (int i = 1; i <= len - k; i ++)
    {
        for (int j = 0; j <= 9; j ++)
        {
            if (len - k + i <= i) continue;
            int rest = f[j][len - k + i] - f[j][i - 1];
            printf ("DEBUG in i=%d: found %d returned %d\n", i, j, rest);
            for (int p = 0; p < rest; p ++)
            {
                printf ("%d", j);
            }
            i += rest;
        }
    }
    return 0;
}