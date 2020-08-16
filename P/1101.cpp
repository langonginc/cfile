#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
namespace scope{
	using namespace std;
	struct pos{
		int x,y;
	};
	pos make(int x,int y){
		pos a;
		a.x=x,a.y=y;
		return a;
	}
	const int dx[9]={0,-1,-1,-1,0,1,1,1,0};
	const int dy[9]={0,-1,0,1,1,1,0,-1,-1};
	int n;
	char ans[9]=" yizhong";
	char field[105][105];
	bool color[105][105];
	queue<pos>bfs;
	bool find(int x,int y,int nx,int ny,int step){
		if(step>=8){
			color[x][y]=1;
			return true;
		}
		int xx=x+nx,yy=y+ny;
		if(field[xx][yy]==ans[step]){
			if(find(xx,yy,nx,ny,step+1)){
				color[x][y]=1;
				return true;
			}
		}
		return false;
	}
}
using namespace scope;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			scanf("%s",&field[i][j]);
			cin>>field[i][j];
			if(field[i][j]=='y'){
				bfs.push(make(i,j));
			}
		}
	}
	while(!bfs.empty()){
		int x=bfs.front().x,y=bfs.front().y;
		bfs.pop();
		for(int k=1;k<=8;k++){
			int xx=x+dx[k],yy=y+dy[k];
			if(field[xx][yy]=='i'){
				if(find(xx,yy,dx[k],dy[k],3)){
					color[x][y]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(color[i][j]){
            	cout<<field[i][j];
			}
            else{
            	cout<<"*";
			}
        }
        cout<<endl;
    }
	return 0;
}
