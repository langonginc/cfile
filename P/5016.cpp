#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;
const ll inf = 100005;
ll n, m, p1, p2, s1, s2, c[inf], dra, lio, mn = LLONG_MAX;

int main ()
{
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%lld", &c[i]);
	}
	scanf ("%lld%lld%lld%lld", &m, &p1, &s1, &s2);
	c[p1] += s1;
	for (ll i = 1; i <= n; i ++)
	{
		if (i < m)
		{
			dra += (m - i) * c[i];
		}
		else if (m < i)
		{
			lio += (i - m) * c[i];
		}
	}
	for (ll i = 1; i <= n; i ++)
	{
		ll x = dra, y = lio, t;
		if (i < m)
		{
			x += (m - i) * s2;
		}
		else if (m < i)
		{
			y += (i - m) * s2;
		}
		if (x > y)
		{
			t = x - y;
		}
		else
		{
			t = y - x;
		}
		if (mn > t)
		{
			mn = t;
			p2 = i;
		}
	}
	printf ("%lld\n", p2);
	return 0;
}