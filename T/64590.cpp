#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, sx, sy;
char x[105], y[105];

// RSP

inline int check(char x, char y)
{
	if (x == y)
		return 0;
	if (x == 'R' && y == 'S')
		return 1;
	if (x == 'S' && y == 'P')
		return 1;
	if (x == 'P' && y == 'R')
		return 1;
	if (x == 'P' && y == 'S')
		return 2;
	if (x == 'S' && y == 'R')
		return 2;
	if (x == 'R' && y == 'P')
		return 2;
	return -1;
}

int main()
{
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++)
	{
		int k = check(x[i], y[i]);
		if (k == 1)
		{
			sx++;
		}
		if (k == 2)
		{
			sy++;
		}
		if (k == -1)
		{
			cout << "ERROR" << endl;
		}
	}
	cout << sx << endl << sy << endl;
	return 0;
}
