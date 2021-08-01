#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 10000005;

int n, a[inf];

void fastsort (int left, int right){
	int i = left, j = right, mid = a[(left + right) >> 1];
	if (left < right)
	{
		while (i <= j)
		{
			while (a[i] < mid) i ++;
			while (mid < a[j]) j --;
			if(i <= j)
			{
				swap (a[i], a[j]);
				i ++, j --;
			}
		}
		fastsort (left, j);
		fastsort (i, right);		
	}
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", &a[i]);
	}
	fastsort (1, n);
	for (int i = 1; i <= n; i ++)
	{
		printf ("%d ", a[i]);
	}
	return 0;
}
