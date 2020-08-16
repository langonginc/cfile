#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int inf=155;
vector<int>child[inf];
int dp[inf][inf],n,p,root,ans=2147483647;
void dfs(int u){
	dp[u][1]=child[u].size();
	for( int i=0; i<child[u].size(); i++){
		int v=child[u][i];
		dfs(v);
		for( int j=p;j>=1;j--){
			for( int k=1; k<=j; k++){
				dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]-1);
			}
		}
	}
	if( u==root){
		ans=min( ans, dp[u][p]);
	}
	else{
		ans=min( ans, dp[u][p]+1);
	}
	return;
}
int gen[inf];
int main(){
	memset( dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&p);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		child[x].push_back(y);
		gen[y]++;
	}
	for(int i=1;i<=n;i++){
		if(gen[i]==0){
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<ans;
	return 0;
}
