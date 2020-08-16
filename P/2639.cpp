#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int heavy,n;
	cin>>heavy>>n;
	int h[n+1],f[n+1][heavy+1];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=heavy;j++){
			if(h[i]>j){
				f[i][j]=f[i-1][j];
			}
			else{
				f[i][j]=max(f[i-1][j],f[i-1][j-h[i]]+h[i]);
			}
		}
	}
	cout<<f[n][heavy];
	return 0;
}
