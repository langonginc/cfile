// luogu-judger-enable-o2
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,ans[1000005],nextcolor;
int nx[4]= {0,0,1,-1};
int ny[4]= {1,-1,0,0};
char mp[1005][1005];
int color[1005][1005];

int fs(int x,int y){
		
	if (color[x][y] != -1)
		return ans[color[x][y]];
	queue<int> q; 
	q.push(x);
	q.push(y);
	int count=1;
	color[x][y]=nextcolor;
	while(!q.empty()){
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nnx=x+nx[i];
			int nny=y+ny[i];
			if (!(nnx > 0 && nnx <= n && nny > 0 && nny <= n))
				continue; 
			//if(nnx>0 && nnx<=n && nny>0 && nny<=m){
			if(mp[nnx][nny]!=mp[x][y] && color[nnx][nny]==-1){
					//r[x][y]=power;
					color[nnx][nny]=nextcolor;
					count++;
					q.push(nnx);
					q.push(nny);
				}
			//}
		}
	}
	ans[nextcolor]=count;
	nextcolor++;
	return count;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	memset(color,-1,sizeof(color));
	nextcolor=0;
	int x,y;
	for(int i=1 ;i<=m ;i++){
		cin>>x >>y ;	
		cout<<fs(x ,y )<<endl;
	}
	
	return 0;
}
