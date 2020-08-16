#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1],f[n+1];
	for(int i=0;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(f[i-1]<0){
			f[i]=a[i];
		}
		else{
			f[i]=f[i-1]+a[i];
		}
	}
	int mx=-900000;
	for(int i=1;i<=n;i++){
		mx=max(mx,f[i]);
	}
	cout<<mx;
	return 0;
}
