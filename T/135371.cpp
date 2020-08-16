#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 2147483647;
const int mxn = 200005;

struct edge{
  int w,v;
};
struct node{
  int pos,dis;
  bool operator <(const node &a)const{
    return dis>a.dis;
  }
};
bool vis[mxn];
int d[mxn], wait[mxn];
vector<edge> adj[mxn];
priority_queue<node> q;
int N,m,s = 1;
void djastl(){
  for(int i=1;i<=N;i++){
    vis[i]=false;
    d[i]=inf;
  }
  node n;
  n.pos=1;
  n.dis=0;
  q.push(n);
  d[1]=0;
  while(!q.empty()){
    n=q.top();
    q.pop();
    if(vis[n.pos]==true){
      continue;
    }
    vis[n.pos]=true;
    for(int i=0;i<adj[n.pos].size();i++){
      int v=adj[n.pos][i].v;
      int w=adj[n.pos][i].w;
      if(d[n.pos]+w+wait[v]<d[v]){
        d[v]=d[n.pos]+w+wait[v];
        node tmp;
        tmp.dis=d[v];
        tmp.pos=v;
        q.push(tmp);
      }
    }
  }
}
int main(){
  scanf("%d%d", &N, &m);
  for (int i = 0; i < m; i ++)
  {
    int u, v, w;
    scanf ("%d%d%d", &u, &v, &w);
    edge a;
    a.v = v, a.w = w;
    adj [u].push_back(a);
  }
  for (int i = 2; i <= N; i ++)
    scanf ("%d", &wait[i]);
  djastl();
  for(int i=2;i<=N;i++){
    cout << (d[i] == inf ? -1 : d[i]) << " ";
  }
  return 0;
}

