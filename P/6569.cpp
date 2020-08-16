#include <cstring>
#include <climits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

class box
{
public:
  ll data [105][105];
  void clear ()
  {
    memset (data, 0, sizeof (data));
  }
};

int Mn = 105;

box add (box a, box b)
{
  box ans;
  ans.clear();
  for(ll i=1;i<=Mn;i++)
  {
    for(ll j=1;j<=Mn;j++)
    {
      ans.data[i][j] = a.data[i][j] + b.data[i][j];
    }
  }
  return ans;
}

box mul (box a, box b)
{
  box ans;
  ans.clear();
  for(ll i=1;i<=Mn;++i)
    for(ll j=1;j<=Mn;++j)
      for(ll k=1;k<=Mn;++k){
        ans.data[i][j] = ans.data[i][j] ^ (a.data[i][k] * b.data[k][j]);
        ans.data[i][j] = ans.data[i][j];
      }
  return ans;
}

ll n, m, q, f [1000005], g2 [1000005];
box a [35]; //g;

void last(ll pos){
	ll tmp[105];
	memset (tmp, 0, sizeof (tmp));
	for (ll i = 1; i <= n; i ++){
		for (ll j = 1; j <= n; j ++){
			if (a [pos]. data [i][j]){
				tmp [i] = tmp [i] ^ g2 [j]; 
			}
		}
	}
	for (ll i = 1; i <= n; i ++){
		g2 [i] = tmp [i];
	}
}

int main ()
{
  cin >> n >> m >> q;
  Mn = n;
  for (ll i = 1; i <= n; i ++)
  {
    scanf ("%lld", &f [i]);
  }
  for (ll i = 1; i <= m; i ++)
  {
    ll u, v;
    cin >> u >> v;
    a [0].data [u][v] = 1;
    a [0].data [v][u] = 1;
  }
  for (ll i = 1; i <= 30; i ++)
  {
    a [i] = mul (a [i - 1], a [i - 1]);
  }

  /*for (int i = 1; i <= q; i ++)
  {
    g = a[0];
    ll k;
    scanf ("%lld", &k);
    for (ll j = 0; j <= 30; j ++)
    {
      if (k & (1ull << j))
      {
        g = mul (g, a [j]);
      }
    }
    printf ("%lld\n", g.data [1][1]);
  }*/

  for (ll i = 1; i <= q; i ++)
  {
    for (ll j = 1; j <= n; j ++)
    {
      g2 [j] = f [j];
    }
    ll k;
    scanf ("%lld", &k);
    for (ll j = 0; j <= 30; j ++)
    {
      if (k & (1ll << j))
      {
        last (j);
      }
    }
    printf ("%lld\n", g2 [1]);
  }
  return 0;
}
