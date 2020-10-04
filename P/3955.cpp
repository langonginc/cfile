#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1005], q;
int mod[9] = { 0,10,100,1000,10000,100000,1000000,10000000,100000000 };

inline int getmod(int x)
{
	switch (x) {
	case 0:return 0;
	case 1:return 10;
	case 2:return 100;
	case 3: return 1000;
	case 4:return 10000;
	case 5:return 100000;
	case 6:return 1000000;
	}
  return 0;
}

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= q; i++)
	{
		int l, qi, ans = -1; 
		cin >> l >> qi;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] % mod[l] == qi) {
				ans = a[j];
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
