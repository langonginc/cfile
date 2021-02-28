#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int inf = 155;
const int INF = 999999999;

#ifndef PointClass
#define PointClass

class Point
{
public:
    int x, y;

    Point();
    double dis (Point p);
};

Point::Point()
{
}

double Point::dis (Point p)
{
    return sqrt(abs(x - p.x) * abs(x - p.x) + abs(y - p.y) * abs(y - p.y));
}

#endif /* end of include guard: PointClass */

int n, f[inf];
double dis[inf][inf], d[inf];
Point a[inf];

void dfs (int index, int id)
{
    f[index] = id;
    for (int k = 1; k <= n; k ++)
    {
        if (!f[k] && dis[index][k] < INF)
        {
            dfs (k, id);
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].x >> a[i].y;
    }
    // char str[inf];
    for (int i = 1; i <= n; i ++)
    {
        // cin >> str;
        for (int j = 1; j <= n; j ++)
        {
            char ch;
            cin >> ch;
            // if (str[j] == '1' || i == j)
            if (ch == '1' || i == j)
            {
                dis[i][j] = a[i].dis(a[j]);
            }
            else
            {
                dis[i][j] = INF;
            }
        }
    }
    int id = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (!f[i])
        {
            dfs (i, ++id);
        }
    }
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    double mx[inf];
    for (int i = 1; i <= n; i ++)
    {
        // mx[i] = 0.0;
        for (int j = 1; j <= n; j ++)
        {
            if (dis[i][j] < INF)
            {
                mx[i] = max (mx[i], dis[i][j]);
            }
        }
        d[f[i]] = max (d[f[i]], mx[i]);
    }
    double mn = 2 * INF;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            if (f[i] != f[j])
            {
                mn = min (mn, max (max (d[f[i]], d[f[j]]), mx[i] + a[i].dis(a[j]) + mx[j]));
            }
        }
    }
    printf ("%.6lf\n", mn);
    return 0;
}
