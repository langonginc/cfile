#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
const int inf=500005;
ll n,dp[inf],k[inf],ans;
char s[inf];
vector<ll> adj[inf];
void dfs(ll u,ll father,ll rem){
	k[u]+=k[father];
	if(s[u]=='('){
		rem++;
		ll save=dp[rem];
		dp[rem]=0;
		for(int i=0;i<adj[u].size();i++){
			dfs(adj[u][i],u,rem);
		}
		dp[rem]=save;
	}
	else{
		if(rem==0){
			ll save=dp[0];
//			k[u]=k[u]+dp[0]+1;
			dp[0]=0;
			for(int i=0;i<adj[u].size();i++){
				dfs(adj[u][i],u,rem);
			}
			dp[0]=save;
		}
		else{
			rem--;
			k[u]=k[u]+dp[rem]+1;
			ll save=dp[rem];
			dp[rem]++;
			for(int i=0;i<adj[u].size();i++){
				dfs(adj[u][i],u,rem);
			}
			dp[rem]=save;
		}
	}
	ans^=u*k[u];
}
int main(){
	scanf("%lld%s",&n,(s+1));
	for(ll i=2;i<=n;i++){
		ll f;
		scanf("%lld",&f);
		adj[f].push_back(i);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
