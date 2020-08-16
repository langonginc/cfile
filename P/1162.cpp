#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,field[35][35];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,-1,1};
void out(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",field[i][j]);
		}
		printf("\n");
	}
}
void prin(int x,int y){
	if(field[x][y]==2||field[x][y]==1){
		return;
	}
	if(field[x][y]==0){
		field[x][y]=2;
		for(int i=0;i<4;i++){
			prin(x+xx[i],y+yy[i]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&field[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(field[i][j]==1&&i!=n){
				if(field[i+1][j]==1)continue;
				if(field[i+1][j]==0){
					prin(i+1,j);
					out();
					exit(0);
				}
			}
		}
	}
	return 0;
}
