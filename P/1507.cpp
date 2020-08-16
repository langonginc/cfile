#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int volume,heavy,n,f[55][405][405];
int main(){
	cin>>volume>>heavy>>n;
	int v[n+1],h[n+1],kal[n+1];//Ç°i¸öÎïÆ·£¬Ìå»ýÎªj£¬ÖÊÁ¿ÎªkÊ±µÄmax; 
	for(int i=1;i<=n;i++){
		cin>>v[i]>>h[i]>>kal[i];
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=volume;j++){
			for(int k=1;k<=heavy;k++){
				if(v[i]>j||h[i]>k){
					f[i][j][k]=f[i-1][j][k];
				}
				else{
					f[i][j][k]=max(f[i-1][j][k],f[i-1][j-v[i]][k-h[i]]+kal[i]);
				}
			}
		}
	}
	cout<<f[n][volume][heavy];
	return 0;
}
