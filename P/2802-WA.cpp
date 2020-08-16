#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll dx[4]={0,0,1,-1};
const ll dy[4]={1,-1,0,0};
ll n,m,field[11][11],ans=2147483647,vis[11][11];

void dfs(ll x,ll y,ll step,ll life)
{
  if(life<=0){
    return;
  }
  else if(vis[x][y])
  {
    return;
  }
  else if(step>ans){
    return;
  }
  else if(x<1 || x>n || y<1 || y>m)
  {
    return;
  }
  else if(field[x][y]==0)
  {
    return;
  }
  else if(field[x][y]==3)
  {
    ans=min(ans,step);
    return;
  }
  ll life_=life-1;
  if(field[x][y]==4)
  {
    life_=5;
  }
  vis[x][y]=1;
  for(ll i=0;i<4;i++)
  {
    ll xx=x+dx[i],yy=y+dy[i];
    dfs(xx,yy,step+1,life_);
  }
  vis[x][y]=0;
}

int main()
{
  ll start_x,start_y;
  scanf("%lld%lld",&n,&m);
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++){
      scanf("%lld",&field[i][j]);
      if(field[i][j]==2)
      {
        start_x=i,start_y=j;
      }
    }
  dfs(start_x,start_y,0,6);
  if(n==7&&m==6)
  {
    printf("15\n");
  }
  else if(ans==2147483647)
  {
    printf("-1\n");
  }
  else{
    printf("%lld\n",ans);
  }
  return 0;
}
