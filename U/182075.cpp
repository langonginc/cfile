#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int inf = 1000005;
ll n, m, a[inf], sum[inf * 4], tag[inf * 4];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void movetag (ll p, ll l, ll r, ll f){
    if (f)
    {
        sum[p] = 0;
	    tag[p] = f;
    }
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
}
void pushdown (ll p, ll l, ll r){
	ll mid = (l + r) >> 1;
	movetag (lc (p), l, mid, tag[p]);
	movetag (rc (p), mid + 1, r, tag[p]);
	tag[p] = 0;
}
void update (ll p, ll l, ll r, ll ql, ll qr, ll d){
	if (ql <= l && r <= qr){
        if (d)
        {
            sum[p] ++;
        }
		else
        {
            sum[p] = 0;
            tag[p] = 1;
        }
		return;
	}
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
	if (ql <= mid){
		update (lc (p), l, mid, ql, qr, d);
	}
	if (mid < qr){
		update (rc (p), mid + 1, r, ql, qr, d);
	}
	pushup (p);
}
ll query (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return sum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1, result = 0;
	if (ql <= mid){
		result += query (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += query (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}

class Query
{
    public:
    int op;
    double x, y;
} q[inf];

double dis[2 * inf];
int ng;

inline int cal (double x)
{
    return lower_bound (dis + 1, dis + ng + 1, x) - dis;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%lf", &q[i].op, &q[i].x);
        dis[++ ng] = q[i].x;
        if (q[i].op != 1)
        {
            scanf ("%lf", &q[i].y);
            dis[++ ng] = q[i].y;
        }
    }
    sort (dis + 1, dis + ng + 1);
    int rt = ng + 2;
    for (int i = 1; i <= n; i ++)
    {
        if (q[i].op == 1)
        {
            // printf ("UPDATE: %lf %d\n", q[i].x, cal(q[i].x));
            update (1, 1, rt, cal(q[i].x), cal(q[i].x), 1);
        }
        else if (q[i].op == 2)
        {
            // printf ("QUERY:x %lf %d\n", q[i].x, cal(q[i].x));
            // printf ("QUERY:y %lf %d\n", q[i].y, cal(q[i].y));
            printf ("%d\n", query (1, 1, rt, cal(q[i].x), cal(q[i].y)));
        }
        else
        {
            // printf ("DELETE:x %lf %d\n", q[i].x, cal(q[i].x));
            // printf ("DELETE:y %lf %d\n", q[i].y, cal(q[i].y));
            update (1, 1, rt, cal(q[i].x), cal(q[i].y), 0);
        }
    }
    return 0;
}
