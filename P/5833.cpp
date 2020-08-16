#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
int n,du[10],f[10][10],vis[10],tot;
string s;
const string cow[9]={" ","Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
void dfs(int u){
    for(int i=1;i<=8;++i){
        if(f[u][i]&&i!=u&&vis[i]==0){
            vis[i]=1;++tot;
            cout<<cow[i]<<endl;
            dfs(i);
            break;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>s;
        for(int j=1;j<9;j++){
            if(s==cow[j]){
                du[j]++;
                u=j;
                break;
            }
        }
        for(int j=1;j<=4;j++){
            cin>>s;
        }
        for(int j=1;j<9;j++){
            if(s==cow[j]){
                du[j]++;
                v=j;
                break;
            }
        }
        f[u][v]=1;
    }
    int now;//,tot=0,vis[10];
    memset(vis,0,sizeof(vis));
    while(tot<8){
        for(int i=1;i<=8;++i){
            if(!vis[i]&&du[i]!=2){
                now=i;
                break;
            }
        }
        cout<<cow[now]<<endl;
        tot++,vis[now]=1;
        if(du[now]==1){
            dfs(now);
        }
    }
    return 0;
}