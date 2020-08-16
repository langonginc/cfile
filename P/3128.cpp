#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
const int INF=INT_MAX;
const int inf=50005;
vector<int> adj[inf];
int n,k,depth[inf],parent[inf][20],diff[inf],flow[inf],lg[inf];
void log(){
    for(int i=1;i<=n;i++){
        lg[i]=lg[i-1]+((1<<lg[i-1])==i);
    }
    return;
}
void lcadfs(int u,int father){
    depth[u]=depth[father]+1;
    parent[u][0]=father;
    for(int i=1;i<17;i++){
        parent[u][i]=parent[parent[u][i-1]][i-1];
    }
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i]!=father){
            lcadfs(adj[u][i],u);
        }
    }
    return;
}
int lca(int x,int y){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    while (depth[x]>depth[y]){
        x=parent[x][lg[depth[x]-depth[y]]-1];
    }
    if(x==y)return x;
    for(int i=lg[depth[x]];i>=0;i--){
        if(parent[x][i]!=parent[y][i]){
            x=parent[x][i],y=parent[y][i];
        }
    }
    return parent[x][0];
}
void dfs(int u,int father){
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i]==father)continue;
        dfs(adj[u][i],u);
        flow[u]+=flow[adj[u][i]];
    }
    flow[u]+=diff[u];
    return;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    log();
    lcadfs(1,0);
    for(int i=1;i<=k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int l=lca(a,b);
        diff[a]++;
        diff[parent[l][0]]--;
        diff[b]++;
        diff[l]--;
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,flow[i]);
    }
    printf("%d",ans);
    return 0;
}

