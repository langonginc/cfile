#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int n=9;
int u1[100][100],u2[100][100],u3[300][300][300],a[100][100];
void math(int x,int y){
	if(x>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		exit(0);
	}
	else{
		if(y>n){
			math(x+1,1);
		}
		else if(a[x][y]!=0){
			math(x,y+1);
		}
		else{
			for(int i=1;i<=n;i++){
				int nx=1+(x>3)+(x>6),ny=1+(y>3)+(y>6);
				if(u1[x][i]==0&&u2[y][i]==0&&u3[nx][ny][i]==0){
					a[x][y]=i;
					u1[x][i]=1;
					u2[y][i]=1;
					u3[nx][ny][i]=1;
					math(x,y+1);
					u1[x][i]=0;
					u2[y][i]=0;
					u3[nx][ny][i]=0;
				}
			}
			a[x][y]=0;
		}
	}
}
int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			int nx=1+(i>3)+(i>6),ny=1+(j>3)+(j>6);
			u1[i][a[i][j]]=1;
			u2[j][a[i][j]]=1;
			u3[nx][ny][a[i][j]]=1;
		}
	}
	math(1,1);
	return 0;
}
