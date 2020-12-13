#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
typedef long long ll;
const int M=2147483647;
ll x,y,n,m,l;
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a; 
	}
	ll g,x1,y1;
	g=extgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return g;
}

int main(){
	ll start=clock();
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if(m<n){
		swap(n,m);
		swap(x,y);
	}
	ll x1,y1,g=extgcd(m-n,l,x1,y1);
	if((y-x)%g!=0){
		printf("Impossible\n");
		return 0;
	}
	x1=x1*(y-x)/g;
	cout<<(x1%(l/g)+(l/g))%(l/g);
	return 0;
}
