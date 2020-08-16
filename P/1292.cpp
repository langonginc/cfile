#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll extgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll x1,y1,g=extgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return g;
}
int main(){
	ll extgcd(ll a,ll b,ll &x,ll &y);
	ll a,b,x0,y0;
	scanf("%lld%lld",&a,&b);
	ll g=extgcd(a,b,x0,y0);
	printf("%lld\n",g);
	ll x=(x0%(b/g)+(b/g))%(b/g);
	if(x!=0){
		x-=b/g;
	}
	ll y=(g-a*x)/b;
	printf("%d %d",-x,y);
	return 0;
}
