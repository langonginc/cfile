#include<iostream>
using namespace std;
int main(){
	//freopen("ds-tr.txt","r",stdin);
	int n,m=0;
	cin>>n;
	int f[n+1][n+1],a[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=max(f[i-1][j]+a[i][j],f[i-1][j-1]+a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		if(f[n][i]>m)m=f[n][i];
	}
	cout<<m;
	return 0;
}
