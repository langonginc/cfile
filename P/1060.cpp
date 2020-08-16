#include<iostream>
#include<cstdio>
using namespace std;
int n,money,w[30],v[30],f[30005];
int main(){
	scanf("%d%d",&money,&n);
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=money;j>0;j--){
			if(w[i]<=j){
				f[j]=max(f[j],f[j-w[i]]+w[i]*v[i]);
			}
		}
	}
	cout<<f[money];
	return 0;
}
