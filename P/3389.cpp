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
      for(ll i=1;i<=Mn;i++)for(ll j=1;j<=Mn;j++)
      {
        data[i][j]=result.get(i,j);
      }
    }
  };
}



#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
using namespace matrix;
typedef long long ll;
const double EPS=0.00001;
const ll MAX=115;
ll n;
double a[MAX][MAX];


int main()
{
  scanf("%lld",&n);
  for(ll i=0;i<n;i++)for(ll j=0;j<=n;scanf("%lf",&a[i][j]),j++);

  for(ll i=0;i<n;i++)
  {
    ll r=i;
    for(ll j=i+1;j<n;j++)
    {
      if(fabs(a[r][j])<fabs(a[j][i]))
      {
        r=j;
      }
    }

    if(r!=i)
    {
      for(ll j=0;j<n+1;j++)
      {
        swap(a[i][j],a[r][j]);
      }
    }

    if(fabs(a[i][i])<EPS)
    {
      printf("No Solution\n");
      return 0;
    }

    for(ll j=i+1;j<n;j++)
    {
      double t=a[j][i]/a[i][i];
      for(ll k=i;k<n+1;k++)
      {
        a[j][k]-=a[i][k]*t;
      }
    }
  }

  for(ll i=n-1;i>=0;i--)
  {
    for(ll j=i+1;j<n;j++)
    {
      a[i][n]-=a[i][j]*a[j][n];
    }
    a[i][n]/=a[i][i];
  }

  for(ll i=0;i<n;i++)
  {
    printf("%.2lf\n",a[i][n]);
  }

  return 0;
}
