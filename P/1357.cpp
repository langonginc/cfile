//P1357 luogu

#include<iostream>
#include<cstdio>
#include<cstring>
namespace matrix{
  using namespace std;
  typedef long long ll;
  ll mod=2147483647,Mn=105;
  class box
  {
    ll data[105][105];

  public:
    void clear()
    {
      memset(data,0,sizeof(data));
    }
    ll get(ll x,ll y)
    {
      return data[x][y];
    }
    void put(ll x,ll y,ll value)
    {
      data[x][y]=value;
    }
    inline void build()
    {
      clear();
      for(int i=0;i<Mn;i++){
        data[i][i]=1;
      }
    }
    box operator + (box c)const{
      box ans;
      ans.clear();
      for(ll i=0;i<Mn;i++)
      {
        for(ll j=0;j<Mn;j++)
        {
          ans.put(i,j,data[i][j]+c.get(i,j));
        }
      }
      return ans;
    }
    void operator += (box c){
      box ans;
      ans.clear();
      for(ll i=0;i<Mn;i++)
      {
        for(ll j=0;j<Mn;j++)
        {
          ans.put(i,j,data[i][j]+c.get(i,j));
          data[i][j]=ans.get(i,j);
        }
      }
    }
    box operator * (box b)const{
      box ans;
      ans.clear();
      for(ll i=0;i<Mn;++i)
        for(ll j=0;j<Mn;++j)
          for(ll k=0;k<Mn;++k){
            ans.put(i,j,ans.get(i,j)+(data[i][k]*b.get(k,j))%mod);
            ans.put(i,j,ans.get(i,j)%mod);
          }
      return ans;
    }
    void operator *= (box b){
      box ans;
      ans.clear();
      for(ll i=0;i<Mn;++i)
        for(ll j=0;j<Mn;++j)
          for(ll k=0;k<Mn;++k){
            ans.put(i,j,ans.get(i,j)+(data[i][k]*b.get(k,j))%mod);
            ans.put(i,j,ans.get(i,j)%mod);
            data[i][j]=ans.get(i,j);
          }
    }
    box operator ^ (long long p)
    {
      box result;
      result.build();
      box base;
      base.clear();
      for(ll i=0;i<Mn;i++)
      {
        for(ll j=0;j<Mn;j++)
        {
          base.put(i,j,data[i][j]);
        }
      }
      while(p)
      {
        if(p&1)
        {
          result=result*base;
        }
        base=base*base;
        p>>=1;
      }
      return result;
    }
    void operator ^= (long long p)
    {
      box result;
      result.build();
      box base;
      base.clear();
      for(ll i=1;i<=Mn;i++)
      {
        for(ll j=1;j<=Mn;j++)
        {
          base.put(i,j,data[i][j]);
        }
      }
      while(p)
      {
        if(p&1)
        {
          result=result*base;
        }
        base=base*base;
        p>>=1;
      }
      for(ll i=1;i<=Mn;i++)for(ll j=1;j<=Mn;j++){
        data[i][j]=result.get(i,j);
      }
    }
  };
}
using namespace std;
using namespace matrix;
typedef long long ll;
box tran;
const ll Bn=1<<5;

ll countx(ll x)
{
  ll ans=0;
  while(x)
  {
    if(x&1)
    {
      ans++;
    }
    x>>=1;
  }
  return ans;
}

ll n,m,k,li,valid[Bn],mask,next,ans;

int main()
{
  tran.clear();
  scanf("%lld%lld%lld",&n,&m,&k);
  li=1<<m;
  Mn=li,mod=1e9+7;
  for(ll i=0;i<li;i++)
  {
    if(countx(i)<=k)
    {
      valid[i]=1;
    }
  }
  mask=(1<<(m-1))-1;

  for(ll i=0;i<li;i++)
  {
    if(valid[i])
    {
      if(valid[(i&mask)<<1])
      {
        tran.put(i,(i&mask)<<1,1);
      }
      if(valid[(i&mask)<<1|1])
      {
        tran.put(i,(i&mask)<<1|1,1);
      }
    }
  }

  box r=tran^n;
  for(ll i=0;i<li;i++)
  {
    if(valid[i])
    {
      ans=(ans+r.get(i,i))%mod;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
