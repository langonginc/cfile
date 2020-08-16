#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,k,len[100005],length;
bool check(ll mid){
	ll sum=0;
	for(ll i=0;i<n;i++){
		sum+=len[i]/mid;
	}
	return sum >= k;
}
int main(){
	scanf("%lld%lld",&n,&k);
	for(ll i=0;i<n;i++){
		scanf("%lld",&len[i]);
		length=max(length,len[i]);
	}
	ll ans=0,low=1,high=length;
	while(low<=high){
		ll mid=(low+high)/2;
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
