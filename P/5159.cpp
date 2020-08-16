#include<iostream>
#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
using namespace std;
typedef long long l;
const int M=2147483647;
const l k=998244353;

l x,y,n;
l mi(l x,l y){
	l result=1%k,temp=x%k;
	while(y){
		if(y&1){
			result=result*temp%k;
		}
		temp=temp*temp%k;
		y>>=1;
	}
	return result;
}
int main(){
	//l n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x>>y;
		cout<<mi(2,(x-1)*(y-1))<<endl;
	}
	return 0;
}
