#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define mms(tpp,xgg) memset(tpp,xgg,sizeof(tpp))
typedef long long ll;
const ll inf=30001;

// 1.计算质数
ll prime[inf],ta[inf],pc;
void pt()
{
  for(ll i=2;i<inf;i++)
  {
    ta[i]=1;
  }
  for(ll i=2;i<inf;i++)
  {
    if(ta[i])
    {
      prime[pc++]=i;
    }
    for(ll j=0;j<pc&&i*prime[j]<inf;j++)
    {
      ta[i*prime[j]]=0;
      if(i%prime[j]==0)
      {
        break;
      }
    }
  }
}

ll a[inf],b[inf],sum[inf];

inline short factor(ll n,short flag)
{
  for(int x=2;x<=n;x++)
  {
    int tx=x;
    for(int i=0;i<pc && tx>1;i++)
    {
      while(tx%prime[i]==0)
      {
        tx/=prime[i];
        a[i]+=flag;
      }
    }
  }
  return flag;
}

void gc(ll n,ll m)
{
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  factor(n,1),
  factor(m,-1),
  factor(n-m,-1);//约分
  b[0]=1;
  for(int i=0;i<pc;i++)
  {
    for(int j=0;j<a[i];j++)
    {
      for(int ti=0;ti<205;ti++)
        b[ti]*=prime[i];
      for(int ti=0;ti<205;ti++){
        b[ti+1]+=b[ti]/10,b[ti]%=10;
      }
    }
  }
  for(int i=0;i<205;sum[i]+=b[i],i++);
  for(int i=0;i<205;sum[i+1]+=sum[i]/10,sum[i]%=10,i++);
}

int main()
{
  ll k,w;
  // scanf("%lld%lld",&k,&w);
  cin>>k>>w;
  pt();
  ll m=k/w,ma=(1<<k)-1;
  for(int i=2;i<=m;i++)
  {
    if(ma>=i)
    {
      gc(ma,i);
    }
  }
  if(w%k!=0 && m>=1)
  {
    ll temp=(1<<(w%k))-1;
    for(int i=1;i<=temp && ma-i>=m;i++)
    {
      gc(ma-i,m);
    }
  }
  ll p=204;
  while(sum[p]==0)p--;
  //p++;
  for(ll i=p;i>=0;i--)
  {
    printf("%lld",sum[i]);
  }
  return 0;
}
