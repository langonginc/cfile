#include<iostream>
#include<cstdio>
using namespace std;
typedef long long l;
int main(){
	l a,b,bb,c;
	cin>>a>>b>>c;
	bb=b;
	if(b==0){
		printf("%d^0 mod %d=0",a,c);
		return 0;
	}
	l r=1,v=a%c;
	while(b){
		if(b&1){
			r=r*v%c;
		}
		v=v*v%c;
		b=b>>1;
	}
	printf("%lld^%lld mod %lld=%lld",a,bb,c,r);
	return 0;
}
