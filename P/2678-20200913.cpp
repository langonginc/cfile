#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;

ll l, n, m, a[500015], cleft = 0, cright, mid, ans = 0;

inline bool check(ll mid)
{
	ll sum = 0, start = 1;
	for (int i = 1; i <= n + 1; i++)
	{
		if (a[i] - a[start] < mid)
		{
			sum++;
		}
		else
		{
			start = i;
		}
	}
	return sum <= m;
}

int main()
{
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = l;
	//sort(a + 1, a + n + 2);
	cleft = 1,cright = l;
	while (cleft <= cright)
	{
		mid = (cleft + cright) / 2;
		if (check(mid))
		{
			ans = mid;
			cleft = mid + 1;
		}
		else
		{
			cright = mid - 1;
		}
	}
	cout << ans;
	return 0;
}