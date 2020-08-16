#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int w[1000][1000],f[1000][1000];
int power;
bool td(int i,int j){
	if(w[i][j]>0&&w[i][j]<=9)return true;
	return false;
}
void print(int x,int y){
	f[x][y]=power;
	if(x-1>=0){
		if(f[x-1][y]==0&&td(x-1,y)){
			print(x-1,y);
		}
	}
	if(x+1<n){
		if(f[x+1][y]==0&&td(x+1,y)){
			print(x+1,y);
		}
	}
	if(y-1>=0){
		if(f[x][y-1]==0&&td(x,y-1)){
			print(x,y-1);
		}
	}
	if(y+1<m){
		if(f[x][y+1]==0&&td(x,y+1)){
			print(x,y+1);
		}
	}
	
}
int main(){
	power=1;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			w[i][j]=s[i][j]-'0';
			f[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]==0&&td(i,j)){
				print(i,j);
				power++;
			}
		}
	}
	cout<<power-1;
	return 0;
}
