#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;

ll gcd (ll x, ll y)
{
    if (y == 0) return x;
    return gcd (y, x % y);
}

class Frac{
    public:
    ll a, b;

    Frac () { a = 0, b = 1; }
    Frac (ll _a, ll _b) { a = _a, b = _b; }

    void easy ()
    {
        ll r = gcd (a, b);
        a /= r, b /= r;
    }

    Frac operator + (const Frac &x) const
    {
        Frac d (a * x.b + x.a * b, b * x.b);
        d.easy();
        return d;
    }
};

vector <int> adj[inf];
queue <int> q;

ll n, m;
int deg[inf], d[inf];
Frac a[inf];

int main ()
{
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        int x;
        scanf ("%d", &d[i]);
        for (int j = 1; j <= d[i]; j ++)
        {
            scanf ("%d", &x);
            adj[i].push_back (x);
            deg[x] ++;
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        a[i].a = 1;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (deg[i] == 0)
        {
            q.push (i);
        }
    }
    while (! q.empty ())
    {
        int u = q.front ();
        q.pop ();
        int x = adj[u].size ();
        if (x == 0) continue;
        Frac g (a[u].a, a[u].b * x);
        for (int i = 0; i <= x; i ++)
        {
            int v = adj[u][i];
            a[v] = a[v] + g;
            a[v].easy ();
            if (-- deg[v] == 0)
            {
                q.push (v);
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] == 0)
        {
            a[i].easy ();
            printf ("%lld %lld\n", a[i].a, a[i].b);
        }
    }
    return 0;
}