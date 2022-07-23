#include<iostream>
#include<cstdio>
using namespace std;
bool a[105][105];
int n, m, xx, yy, maxn;
int dfs(int x,int y,int ans){
    for(int i= xx; i<= x; i++)//cha正方形的左边 
        if(!a[i][y])
            return 0;
    for(int j= yy; j<= y; j++)//cha正方形的下面 
        if(!a[x][j])
            return 0;
    //往右下角走 
    return max(ans,dfs(x+1,y+1, ans+1));
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)//枚举
        for(int j=1;j<=m;j++)
            if(a[i][j]== true){//枚举左上角 
                xx=i; 
                yy=j;
                maxn=max(maxn,dfs(i,j,1));
            }
    cout<<maxn<<endl;
    return 0;
}