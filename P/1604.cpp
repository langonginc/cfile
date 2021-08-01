#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char *tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, a[2005], b[2005], c[5005], len1, len2, len;
string s1, s2;

int change (char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	return ch - 'A' + 10;
}

int main ()
{
	cin >> n >> s1 >> s2;
	len1 = s1.length(), len2 = s2.length();
	len = max (len1, len2);
	for (int i = 0; i < len1; i ++) a[i] = change(s1[len1 - i - 1]);
	for (int i = 0; i < len2; i ++) b[i] = change(s2[len2 - i - 1]);
	for (int i = 0; i < len; i ++)
	{
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / n;
		c[i] %= n;
	}
	len = 2001;
	while (c[len] == 0) len --;
	while (len >= 0) printf ("%c", tab[c[len --]]);
	return 0;
}
