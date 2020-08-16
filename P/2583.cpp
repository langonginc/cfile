#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#include<cstdlib> 
#include<set>
#include<vector> 
#include<climits>
using namespace std;
typedef const int const_int_2;
const_int_2 INF=INT_MAX/3;
const int inf1=2005,inf2=55;
int train[inf1][inf2][2],ti[inf1],dp[inf1][inf2];
void f(int n,int t,int kase){
	for(int i=0;i<=n;i++){
		dp[t][i]=INF;
	}
	dp[t][n]=0;
	for(int i=t-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i+1][j]+1;
			if(j<n&&i+ti[j]<=t&&train[i][j][0]){//r=0。在i时间，j车站，向右方向TRUE 
				dp[i][j]=min(dp[i][j],dp[i+ti[j]][j+1]);
			}
			if(j>1&&i+ti[j-1]<=t&&train[i][j][1]){//l=1
				dp[i][j]=min(dp[i][j],dp[i+ti[j-1]][j-1]);
			}
		}
	}
	if(dp[0][1]>=INF){
		printf("Case Number %d: impossible\n",kase);
	}
	else{
		printf("Case Number %d: %d\n",kase,dp[0][1]);
	}
	return;
}
int n,t,m1,m2,start,num=0;
int main(){
//	int last_n=0,last_t=0;
	while(++num){
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d",&t);
		memset(train,0,sizeof(train));
		memset(ti,0,sizeof(ti));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<n;i++){
			scanf("%d",&ti[i]);
		}
		scanf("%d",&m1);
		for(int i=1;i<=m1;i++){
			scanf("%d",&start);
//			train[start][1][0]=true;
			for(int j=1;j<=n;j++){
				train[start][j][0]=true;
				start+=ti[j];
			} 
		}
		scanf("%d",&m2);
		for(int i=1;i<=m2;i++){
			scanf("%d",&start);
//			train[start][n][1]=true;
			for(int j=n;j>=1;j--){
				train[start][j][1]=true;
				start+=ti[j-1];
			}
		}
		f(n,t,num);
//		last_n=n,last_t=t;
	}
	return 0;
} 
