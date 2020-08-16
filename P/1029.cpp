#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int M=2147483647;
ll s,b,p,q,result=0;
ll gcd(ll a,ll b){
	 if(b==0){
	 	return a;
	 }
	 else{
	 	return gcd(b,a%b);
	 }
}
int main(){
	scanf("%lld%lld",&s,&b);
	for(ll i=s;i<=b;i+=s){
		p=i;
		q=b*s/p;
//		cout<<p<<"&"<<q<<endl;
		if(gcd(p,q)==s&&p*q==b*s){
//			cout<<p<<"%"<<q<<endl;
			result++;
		}
	}
	cout<<result;
	return 0;
}
