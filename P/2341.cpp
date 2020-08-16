#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n,m,du[400000],sccno[400000],val[400000],sccco,dfstime,pre[400000],low[400000];
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
      val[sccco]++;
      if(t==u)
        break;
    }
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    adj[x].push_back(y);
  }
  for(int i=1;i<=n;i++)
    if(pre[i]==0)
      tarjan(i);
  for(int i=1;i<=n;i++)
    for(int j=0;j<adj[i].size();j++)
      if(sccno[i]!=sccno[adj[i][j]])
        link[sccno[i]].push_back(sccno[adj[i][j]]);
  // for(int i=1;i<=sccco;i++)
  //   du[i]+=link[i].size();
  int ans=0,pos=0;
  for(int i=1;i<=sccco;i++)
    if(link[i].size()==0)
      ans++,pos=i;
  printf("%d\n",ans==1?val[pos]:0);
  return 0;
}
