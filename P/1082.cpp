#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int M=2147483647;
ll extgcd(ll a,ll b,ll &x,ll &y){
	 if(b==0){
	 	x=1,y=0;
	 	return a;
	 }
	 ll xx,yy,g=extgcd(b,a%b,xx,yy);
	 x=yy;
	 y=xx-a/b*yy;
	 return g;
}
int main(){
	ll a,b,c=1,d=1,g;
	scanf("%lld%lld",&a,&b);
	g=extgcd(a,b,c,d);
	printf("%lld",(c%b+b)%b);
	return 0;
}
