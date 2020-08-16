#include<iostream>
using namespace std;
typedef long long ll;
#include<cstdio>
//#include<TS>
ll a[100000000],b[100000000],n,ans;
void merge(ll left,ll right){
	for(ll i=left;i<=right;i++){
		b[i]=a[i];
	}
	ll mid=(left+right)/2;
	ll i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right){
		if(b[i]<=b[j]){
			a[k++]=b[i++];
		}
		else{
			a[k++]=b[j++];
			ans+=mid+1-i;
		}
	}
	while(i<=mid)
	{
		a[k++]=b[i++];
	}
	while(j<=right)
	{
		a[k++]=b[j++];
	}
}
void mergesort(ll left,ll right){
	if(left<right){
		mergesort(left,(left+right)/2);
		mergesort((left+right)/2+1,right);
		merge(left,right);
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	mergesort(1,n);
//	for(ll i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	cout<<ans;
	return 0;
}
