#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,money,time;
	cin>>n>>money>>time;
	int m[n+1],t[n+1],f[n+1][money+1][time+1];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>m[i]>>t[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=money;j++){
			for(int k=1;k<=time;k++){
				if(m[i]>j||t[i]>k){
					f[i][j][k]=f[i-1][j][k];
				}
				else{
					f[i][j][k]=max(f[i-1][j][k],f[i-1][j-m[i]][k-t[i]]+1);
				}
			}
		}
	}
	cout<<f[n][money][time];
	return 0;
}
