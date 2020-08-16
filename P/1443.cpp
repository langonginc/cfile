#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int nx[10]={-2,-2,-1,-1,1,1,2,2};
int ny[10]={-1,1,-2,2,-2,2,-1,1};
int main(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int mp[2*n][2*m];
	memset(mp,-1,sizeof(mp));
	queue<int> q;
	q.push(x);
	q.push(y);
	mp[x][y]=0;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		int b=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nnx=a+nx[i];
			int nny=b+ny[i];
			if(nnx>0&&nnx<=n&&nny>0&&nny<=m){
				if(mp[nnx][nny]==-1){
					mp[nnx][nny]=mp[a][b]+1;
					q.push(nnx);
					q.push(nny);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
