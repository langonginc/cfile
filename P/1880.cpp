#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int M=2147483647;
int n,v[105],f[105][105],F[105][105];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	int a,b;
	for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++){
			int now=0;
			int debugS=f[j][j]+f[(j+1)%n][(j+i-1)%n];
			int debugB=F[j][j]+F[(j+1)%n][(j+i-1)%n];
			for(int k=j;k<i+j;k++){
				now+=v[k%n];
			}
			for(int k=j+1;k<j+i-1;k++){
				debugB=max(debugB,F[j][k%n]+F[(k+1)%n][(j+i-1)%n]);
				debugS=min(debugS,f[j][k%n]+f[(k+1)%n][(j+i-1)%n]);
			}
			F[j][(j+i-1)%n]=debugB+now;
			f[j][(j+i-1)%n]=debugS+now;
//			cout<<i<<" "<<j<<" "<<f[j][(j+i-1)%n]<<" "<<F[j][(j+i-1)%n]<<endl;
			a=j,b=(j+i-1)%n;
		}
	}
	int B=0-M,S=M;
	for(int i=0;i<n;i++){
		int end=(i+n-1)%n;
		B=max(B,F[i][end]);
		S=min(S,f[i][end]);
	}
//	cout<<a<<"%"<<b<<endl;
	cout<<S<<endl<<B;
	return 0;
}
