#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int w[7] = {2, 3, 5, 7, 11, 13, 17};
string str;
stack <int> x;
int num[55], len, xlen, numpos, numlen;

void add (int i)
{
	int power = 1;
	for (int j = i + xlen; j > i; j --)
	{
		num[numpos] += power * (str[j] - '0');
		power *= 10;
	}
//	printf (" [ADD] Catched num[%d]=%d\n", numpos, num[numpos]);
	xlen = 0;
}

int main ()
{
	cin >> str;
	len = str.length();
	int i;
	for (i = len - 1; i >= 0; i --)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			xlen ++;
		}
		if (str[i] == ',')
		{
			add (i);
			numpos ++;
		}
		if (str[i] == '+')
		{
			add (i);
			numlen = max (numlen, numpos);
			numpos = 0;
		}
	}
	add (i);
	numlen = max (numlen, numpos);
	numlen ++;
	for (int i = 0; i < numlen; i ++)
	{
		num[i + 1] += num[i] / w[i];
		num[i] %= w[i];
	}
	numlen = 54;
	while (num[numlen] == 0) numlen --;
	while (numlen > 0) printf ("%d,", num[numlen --]);
	printf ("%d", num[0]);
	return 0;
}
