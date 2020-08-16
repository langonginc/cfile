#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
const int inf=105;
int t,n,m,dp[10005],ans,price[inf][inf];
int main(){
	scanf("%d%d%d",&t,&n,&m);
	ans=m;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&price[i][j]);
		}
	}
	for(int i=1;i<t;i++){
		memset(dp,~0x3f,sizeof(dp));
		dp[ans]=ans;
		for(int j=1;j<=n;j++){
			for(int k=ans;k>=price[i][j];k--){
				dp[k-price[i][j]]=max(dp[k-price[i][j]],dp[k]+price[i+1][j]-price[i][j]);
			}
		}
		int ma=0;
		for(int j=0;j<=ans;j++){
			ma=max(ma,dp[j]);
		}
		ans=ma;
	}
	printf("%d",ans);
	return 0;
}
