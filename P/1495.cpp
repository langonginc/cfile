#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
template <class Tp> Tp exgcd(Tp a,Tp b,Tp &x,Tp &y)
{
  if(b==0)
  {
    x=1,y=0;
    return a;
  }
  else
  {
    Tp x1,y1,g=exgcd<Tp>(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return g;
  }
}

ll n,a[20],b[20],mi,m=1,ans=0,t,y;

int main()
{
  scanf("%lld",&n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld",&a[i],&b[i]);
    m*=a[i];
  }
  for(int i=0;i<n;i++){
    mi=m/a[i];
    exgcd<ll>(mi,a[i],t,y);
    ans=(ans+b[i]*mi*t)%m;
  }
  printf("%lld",(ans+m)%m);
}
