#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
double in;
ll n,l[100005],k,ans;
bool check(ll mid){
	if(mid==0)return true;
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=l[i]/mid;
	}
	return sum>=k;
}
int main(){
	cin>>n>>k;
	ll mxl=0;
	for(ll i=0;i<n;i++){
		cin>>in;
		l[i]=in*100;
		mxl=max(mxl,l[i]);
	}
	ll left=0,right=mxl;
	while(left<=right){
		ll mid=(left+right)/2;
		if(check(mid)){
			left=mid+1;
			ans=mid;
		}
		else{
			right=mid-1;
		}
	}
	double a=ans;
	double re=a/100;
//	cout<<re<<endl;
	printf("%.2f",re);
	return 0;
}
