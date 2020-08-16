#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int M=2147483647;
ll n,len[500005],l,m;
bool check(ll mid){
	ll c=0,last=0;
	for(int i=1;i<=n;i++){
		if(len[i]-len[last]<mid){
			c++;
		}
		else{
			last=i;
		}
	}
	if(l-len[last]<mid){
		c++;
	}
	return c<=m;
}
int main(){
	scanf("%lld%lld%lld",&l,&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&len[i]);
	}
	ll left=1,right=l,mid,result=1	;
	while(left<=right){
		mid=(left+right)/2;
		if(check(mid)){
			result=mid;
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<result;
	return 0;
}
