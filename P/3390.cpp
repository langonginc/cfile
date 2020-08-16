#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
namespace matrix{
  typedef long long ll;
  ll mod=1e9+7,Mn=105;
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
      for(int i=1;i<=Mn;i++){
        data[i][i]=1;
      }
    }
    box operator + (box c)const{
      box ans;
      ans.clear();
      for(ll i=1;i<=Mn;i++)
      {
        for(ll j=1;j<=Mn;j++)
        {
          ans.put(i,j,data[i][j]+c.get(i,j));
        }
      }
      return ans;
    }
    box operator * (box b)const{
      box ans;
      ans.clear();
      for(ll i=1;i<=Mn;++i)
        for(ll j=1;j<=Mn;++j)
          for(ll k=1;k<=Mn;++k){
            ans.put(i,j,ans.get(i,j)+(data[i][k]*b.get(k,j))%mod);
            ans.put(i,j,ans.get(i,j)%mod);
          }
      return ans;
    }
    box pow(long long p)const
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
      return result;
    }
  };
}


typedef long long ll;
using namespace matrix;



int main(){
  ll n,k;
  scanf("%lld%lld",&n,&k);
  box a;
  Mn=n;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      ll x;
      scanf("%lld",&x);
      a.put(i,j,x);
    }
  }
  a=a.pow(k);
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=n;j++)
    {
      printf("%lld ",a.get(i,j));
    }
    printf("\n");
  }
  return 0;
}

