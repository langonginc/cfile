#include<iostream>
#include<cstdio>
#include <vector>
#include <stack>
using namespace std;
int n,m,w[400000],sccno[400000],sccwo[400000],sccco,dfstime,pre[400000],low[400000];
int dp[400000];
vector<int> adj[400000];
vector<int> link[400000];
stack<int>s;

void tarjan(int u)
{
  pre[u]=low[u]=++dfstime;
  s.push(u);
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(pre[v]==0)
    {
      tarjan(v);
      low[u]=min(low[u],low[v]);
    }
    else if(sccno[v]==0)
      low[u]=min(low[u],pre[v]);
  }
  if(low[u]==pre[u])
  {
    ++sccco;
    while(true)
    {
      int t=s.top();
      s.pop();
      sccno[t]=sccco;
      sccwo[sccco]+=w[t];
      if(t==u)
        break;
    }
  }
}

int dfs(int u)
{
  if(dp[u]!=0)
    return dp[u];
  for(int i=0;i<link[u].size();i++)
    dp[u]=max(dp[u],dfs(link[u][i]));
  dp[u]+=sccwo[u];
  return dp[u];
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&w[i]);
  }
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    adj[x].push_back(y);
  }
  for(int i=1;i<=n;i++)
    if(pre[i]==0)
      tarjan(i);
  for(int i=1;i<=n;i++)for(int j=0;j<adj[i].size();j++)
  {
    int v=adj[i][j];
    if(sccno[i]!=sccno[v])
      link[sccno[i]].push_back(sccno[v]);
  }
  for(int i=1;i<=sccco;i++)
    if(dp[i]==0)
      dfs(i);
  int ans=0;
  for(int i=1;i<=sccco;i++)
    ans=max(ans,dp[i]);
  printf("%d",ans);
  return 0;
}
