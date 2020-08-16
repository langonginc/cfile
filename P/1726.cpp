#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=5005;
int n,m,sccco,sccno[inf],dfstime,pre[inf],low[inf],val[inf],maxvalue,maxfirst;
stack<int>s;
vector<int> adj[inf];
vector<int> ans[inf];
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
      ans[sccco].push_back(t);
      sccno[t]=sccco;
      if(t==u)
        break;
    }
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
  {
    int x,y,t;
    scanf("%d%d%d",&x,&y,&t);
    adj[x].push_back(y);
    if(t==2)adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
    if(pre[i]==0)
      tarjan(i);
  for(int i=1;i<=sccco;i++){
    if(maxvalue<ans[i].size()){
      maxvalue=ans[i].size();
      maxfirst=i;
    }
  }
  printf("%d\n",maxvalue);
  for(int i=0;i<ans[maxfirst].size();i++)
  {
    val[i]=ans[maxfirst][i];
  }
  sort(val,val+maxvalue);
  for(int i=0;i<ans[maxfirst].size();i++)
  {
    printf("%d ",val[i]);
  }
  return 0;
}
