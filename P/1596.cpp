#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans;
char map[10000][10000];
void field(int x,int y){
	map[x][y]='.';
	if(x>0&&y>0)	
		if(map[x-1][y-1]=='W'){
			field(x-1,y-1);
		}
	if(x>0) 
		if(map[x-1][y]=='W'){
			field(x-1,y);
		}
	if(x>0&&y<=m-1)
		if(map[x-1][y+1]=='W'){
			field(x-1,y+1);
		}
	if(y<=m-1)
		if(map[x][y+1]=='W'){
			field(x,y+1);
		}
	if(x<=n-1&&y<=m-1)
		if(map[x+1][y+1]=='W'){
			field(x+1,y+1);
		}
	if(x<=n-1)
		if(map[x+1][y]=='W'){
			field(x+1,y);
		}
	if(x<=n-1&&y>0)
		if(map[x+1][y-1]=='W'){
			field(x+1,y-1);
		}
	if(y>0)
		if(map[x][y-1]=='W'){
			field(x,y-1);
		}
}
int main(){
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		//	scanf("%c",&map[i][j]);
			cin>>map[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]=='W'){
				ans++;
				field(i,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
