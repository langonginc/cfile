#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//#include<windows.h>
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
//	ll step=0;
//	ll p1=x,p2=y;
//	while(p1!=p2){
////		if(clock()-start>950){
////			printf("Impossible\n");
////			return 0;
////		}
//		p1=(p1+m)%l;
//		p2=(p2+n)%l;
//		step++;
//	}
//	printf("%lld\n",step);
	x1=x1*(y-x)/g;
	cout<<(x1%(l/g)+(l/g))%(l/g);
	return 0;
}
