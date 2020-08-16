#include<cstring>
namespace matrix{
  using namespace std;
  typedef long long ll;
  ll mod=2147483647,Mn=105;
  class box
  {
    public:
    ll data[105][105];


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
    void operator += (box c){
      box ans;
      ans.clear();
      for(ll i=1;i<=Mn;i++)
      {
        for(ll j=1;j<=Mn;j++)
        {
          ans.put(i,j,data[i][j]+c.get(i,j));
          data[i][j]=ans.get(i,j);
        }
      }
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
    void operator *= (box b){
      box ans;
      ans.clear();
      for(ll i=1;i<=Mn;++i)
        for(ll j=1;j<=Mn;++j)
          for(ll k=1;k<=Mn;++k){
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
#include<iostream>
#include<cstdio>
using namespace std;
using namespace matrix;
typedef long long ll;
ll t,n;

int main()
{
  mod=1e9+7,Mn=3;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&n);
    if(n<=3)
    {
      printf("1\n");
    }
    else
    {
      box a;
      a.clear();
      a.data[1][1]=a.data[1][3]=a.data[2][1]=a.data[3][2]=1;
      a^=(n-3);
      printf("%lld\n",(a.data[1][1]+a.data[1][2]+a.data[1][3])%mod);
    }
  }
  return 0;
}
