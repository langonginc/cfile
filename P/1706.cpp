#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000];
bool f[1000];
void try_(int d){
	if(d>n){
		for(int i=1;i<n+1;i++){
			printf("%5d",a[i]+1);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++){
		if(f[i]){
			a[d]=i;
			f[i]=false;
			try_(d+1);
			f[i]=true;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[i]=0;
		f[i]=true;
	}
	try_(1);
	return 0;
}
