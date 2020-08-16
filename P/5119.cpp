#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int M=2147483647;
ll n,m,p,t[1000005],maxT=0;
bool check(ll mid){
	ll last=1,bas=1,per=1;
	for(ll i=2;i<=n;i++){
		if(per>=p||t[i]-t[last]>mid){
			bas++;
			last=i;
			per=1;
		}
		else{
			per++;
		}
	}
	return bas<=m;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&t[i]);
		maxT=max(maxT,t[i]);
	}
	sort(t+1,t+n+1);
	ll left=1,mid,right=maxT,ans;
	while(left<=right){
		mid=(left+right)/2;
		if(check(mid)){
			ans=mid;
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
