#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
inline ll lb(ll x){
	return x&-x;
}
ll n,m,c[500005];
void update(ll x,ll d){
	while(x<=n){
		c[x]+=d;
		x+=lb(x);
	}
}
ll sum(ll x){
	ll res=0;
	while(x>0){
		res+=c[x];
		x-=lb(x);
	}
	return res;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		ll d;
		scanf("%lld",&d);
		update(i,d);
	}
	for(int i=1;i<=m;i++){
		ll t,x,y;
		scanf("%lld%lld%lld",&t,&x,&y);
		if(t==1)update(x,y);
		else printf("%lld\n",sum(y)-sum(x-1));
	}
	return 0;
}
