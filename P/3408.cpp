#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int inf=500005;
vector<ll>son[inf];
ll n,t,c,dp[inf],a[inf];
ll f(ll root){
	if(son[root].empty()){
		return a[root];
	}
	vector<ll>price;
	for(ll i=0;i<son[root].size();i++){
		price.push_back(f(son[root][i]));
	}
	sort(price.begin(),price.end());
	ll ans=0,base;
	if(root==0){
		base=c;
	}
	else{
		base=a[root];
	}
	for(ll i=0;i<1.0*base*son[root].size()/t;i++){
		ans+=price[i];
	}
	return ans;
}
int main(){
	scanf("%lld%lld%lld",&n,&t,&c);
	for(int i=1;i<=n;i++){
		ll b;
		scanf("%lld%lld",&b,&a[i]);
		son[b].push_back(i);
	}
	a[0]=c;
	cout<<f(0);
	return 0;
}
