#include <iostream>
#include <cstdio>
using namespace std;
int n, a[1000];
bool vis[1000];
void dfs (int d)
{
	if (d > n)
	{
		for (int i = 1; i <= n; i ++)
		{
			printf ("%5d", a[i]);
		}
		printf ("\n");
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (vis[i] == false)
		{
			a[d] = i;
			vis[i] = true;
			dfs (d + 1);
			vis[i] = false;
		}
	}
}
int main()
{
	scanf ("%d", &n);
	dfs (1);
	return 0;
}
