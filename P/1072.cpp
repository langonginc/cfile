#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const ll max_prime = 45000;
ll prime[max_prime], valid[max_prime], np;

void getPrime()
{
	for (ll i = 2; i < max_prime; i ++)
	{
		valid[i] = 1;
	}
	for (ll i = 2; i < max_prime; i ++)
	{
		if (valid[i])
		{
			prime[np ++] = i;
		}
		for (ll j = 0; j < np && prime[j] * i < max_prime; ++j) {
			valid[prime[j] * i] = 0;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}

ll a0, a1, b0, b1, ans;

void cal(ll p)
{
	ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	while (a0 % p == 0)
	{
		a0 /= p;
		t1 ++;
	}
	while (a1 % p == 0)
	{
		a1 /= p;
		t2 ++;
	}
	while (b0 % p == 0)
	{
		b0 /= p;
		t3 ++;
	}
	while (b1 % p == 0)
	{
		b1 /= p;
		t4 ++;
	}
	if (t1 == t2)
	{
		if (t3 < t4)
		{
			if (t4 < t2)
			{
				ans = 0;
			}
		}
		else
		{
			if (t4 >= t2){
				ans *= (t4 - t2 + 1); 
			}
			else{
				ans = 0;
			}
		}
	}
	else
	{
		if (t3 < t4)
		{
			if (t2 != t4)
			{
				ans = 0;
			}
		}
		else
		{
			if (t2 > t4)
			{
				ans = 0;
			}
		}
	}
}

int main ()
{
	getPrime();
	int n;
	cin >> n;
	while (n --)
	{
		cin >> a0 >> a1 >> b0 >> b1;
		ans = 1;
		for (int i = 0; i < max_prime && prime[i] * prime[i] <= max(a0,b1) && ans; i ++)
		{
			cal(prime[i]);
		}
		if (a0 > 1)
		{
			cal(a0);
		}
		if (b1 > 1)
		{
			cal(b1);
		}
		cout << ans << endl;
	}
	return 0;
}
