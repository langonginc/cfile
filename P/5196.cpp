/**
*USACO19Jan
*In Luogu P5196
**/

#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll inf=5005;
const ll mod=1e9+7;
class words
{
  ll l,y;
public:
  ll& operator[] (int t)
  {
    if(t==1)return l;
    return y;
  }
};

ll fastPow(ll x, ll y, ll mod)
{
  ll r=1%mod,base=x%mod;
  while(y){
    if(y&1)
      r=r*base%mod;
    base=base*base%mod,y>>=1;
  }
  return r%mod;
}

int n,m,k,ans[inf],res=1,f[inf][inf],s[inf],apl[30];
int wd[inf][3];

int main()
{
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",&wd[i][1],&wd[i][2]);
  }
  for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)
  {
    if(i>=wd[j][1])
    {
      f[i][wd[j][2]]=(f[i][wd[j][2]]+s[i-wd[j][1]])%mod;
      s[i]=(s[i]+s[i-wd[j][1]])%mod;
    }
  }
  for(int i=1;i<=m;i++)
  {
    char ch;
    cin>>ch;
    apl[ch-'A']++;
  }
  res=1;
  for(int i=0;i<26;i++)
  {
    if(apl[i])
    {
      int ans=0;
      for(int j=1;j<=n;j++)
      {
        if(f[k][j])
        {
          ans=(ans+fastPow(f[k][j],apl[i],mod))%mod;
        }
      }
      res=res*ans%mod;
    }
  }
  printf("%d\n",res%mod);
  return 0;
}
