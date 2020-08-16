#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct pos{
	int x,y;
	pos(int x,int y):x(x),y(y){}
};
//typedef long long ll;
const int M=2147483647;
int n,m,p[1005][1005],maxL;
int viv[1005][1005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool bfs(int maxN){
	int x=1,y=1;
	queue<pos> q;
	q.push(pos(x,y));
	while(!q.empty()){
		x=q.front().x;
		y=q.front().y;
		q.pop();
		for(int i=0;i<4;i++){
			int xx=dx[i]+x;
			int yy=dy[i]+y;
			if(xx<1||yy<1||xx>n||yy>m){
				continue;
			}
			else if(viv[xx][yy]!=0||p[xx][yy]>maxN){
				continue;
			}
			else{
				viv[xx][yy]=1;
				if(xx==n){
					return true;
				}
				else{
					q.push(pos(xx,yy));
				}
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&p[i][j]);
			maxL=max(maxL,p[i][j]);
		}
	}
	int left=1,mid,right=maxL,ans=0;
	while(left<=right){
		mid=(left+right)/2;
		memset(viv,0,sizeof(viv));
		if(bfs(mid)==true){
			ans=mid;
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
