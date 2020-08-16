#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
void swap(ll &a,ll &b)
{
  ll t=a;a=b;b=t;
}
template <class tp> class vec{
  tp a[100005],back=0;

public:

  tp& operator[] (ll i)
  {
    return a[i];
  }

  inline bool push(tp x)
  {
    if(back<100005)
    {
      a[back++]=x;
      return 0;
    }
    else
    {
      return 1;
    }
  }

  inline void operator() (ll k)
  {
    for(int i=0;i<=k;i++)
    {
      a[i]=i;
    }
  }
};

ll n,m,k,l[100005],r[100005];

vec<ll> trans(vec<ll> x,vec<ll> r)
{
  vec<ll>ans;
  for(ll i=1;i<=n;i++)
  {
    ans[i]=x[r[i]];
  }
  return ans;
}

vec<ll> init(void)
{
  vec<ll>a;
  a(n);

  for(ll i=0;i<m;i++)
  {
    for(ll j=l[i],k=r[i];j<k;j++,k--)
    {
      swap(a[j],a[k]);
    }
  }
  return a;
}

int main()
{
  scanf("%lld%lld%lld",&n,&m,&k);
  for(ll i=0;i<m;scanf("%lld%lld",&l[i],&r[i]),i++);
  vec<ll>a;
  vec<ll>base=init();
  a(n);

  while(k)
  {
    if(k&1)
    {
      a=trans(a,base);
    }
    base=trans(base,base);
    k>>=1;
  }

  for(ll i=1;i<=n;printf("%lld\n",a[i]),i++);
  return 0;
}
