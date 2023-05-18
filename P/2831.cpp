#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxN = 19;
const double eps = 1e-8;


int n, m;
double x[maxN], y[maxN];

bool onFunc (double a, double b, double x, double y)
{
    double _y = a * x * x + b * x;
    if (y - _y < eps && y - _y > -eps)
    {
        return true;
    }
    else return false;
}

namespace getFunc
{
    inline double a (double x1, double y1, double x2, double y2, double x3, double y3)
    {
        return ((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)) / ((x2 * x2 - x1 * x1) * (x3 - x1) - (x3 * x3 - x1 * x1) * (x2 - x1));
    }
    inline double b (double x1, double y1, double x2, double y2, double x3, double y3)
    {
        return ((y2 - y1) - a (x1, y1, x2, y2, x3, y3) * (x2 * x2 - x1 * x1)) / (x2 - x1);
    }
    inline double c (double x1, double y1, double x2, double y2, double x3, double y3)
    {
        return y1 - a (x1, y1, x2, y2, x3, y3) * x1 * x1 - b (x1, y1, x2, y2, x3, y3) * x1;
    }
}

int line[maxN][maxN], start[1 << maxN];
int dp[1 << maxN];

int main ()
{
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < (1 << maxN); i ++)
    {
        int t = 1;
        while ((i & (1 << (t - 1))) == 1) t ++;
        start[i] = t;
    }
    for(int i=0;i<(1<<18);i++){
		int j=1;
		for(;j<=18 && i&(1<<(j-1));j++);
		start[i]=j;
	}
    while (T --)
    {
        memset (line, 0, sizeof (line));
		memset (dp, 0x3f, sizeof (dp));
        dp[0] = 0;
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%lf%lf", &x[i], &y[i]);
        }
        for (int i = 1; i <= n; i ++)
        {
            for (int j = i + 1; j <= n; j ++)
            {
                if (x[i] - x[j] < eps && x[i] - x[j] > -eps)
                {
                    continue;
                }
                double a = getFunc::a (x[i], y[i], x[j], y[j], 0, 0);
                double b = getFunc::b (x[i], y[i], x[j], y[j], 0, 0);
                for (int k = 1; k <= n; k ++)
                {
                    if (onFunc (a, b, x[k], y[k]))
                    {
                        line[i][j] |= (1 << (k - 1));
                    }
                }
            }
        }
        for (int i = 0; i < (1 << n); i ++)
        {
            int j = start[i];
            dp[i | (1 << (j - 1))] = min (dp[i | (1 << (j - 1))], dp[i] + 1);
            for (int k = 1; k <= n; k ++)
            {
                dp[i | line[j][k]] = min (dp[i | line[j][k]], dp[i] + 1);
            }
        }
        printf ("%d\n", dp[(1 << n) - 1]);
    }
    return 0;
}
