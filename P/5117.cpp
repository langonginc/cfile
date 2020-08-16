#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
int t[10005],s[10005],b[10005],d[10005],a[10005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i],&t[i],&b[i]);
		d[s[i]]+=b[i],d[t[i]+1]-=b[i];
	}
	for(int i=1;i<=1001;i++){
		a[i]=a[i-1]+d[i];
	}
	int ans=0;
	for(int i=1;i<=1001;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
