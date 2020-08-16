#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct type{
	int dis1,dis2;
}a[100005];
int distance(int x,int y,int a,int b){
	int asd=(x-a)*(x-a)+(y-b)*(y-b);
	return asd;
}
bool cmp(type f,type s){
	return f.dis1<s.dis1;
}
int main(){
	int x1,x2,y1,y2,n;
	cin>>x1>>y1>>x2>>y2>>n;
	int f[n+2],x,y,maxvalue=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i].dis1=distance(x,y,x1,y1);
		a[i].dis2=distance(x,y,x2,y2);
	}
	int s=n+1;
	sort(a,a+s,cmp);
	a[n+1].dis2=0,a[0].dis1=0;
	for(int i=n;i>=0;i--){
		maxvalue=max(maxvalue,a[i+1].dis2);
		f[i]=maxvalue+a[i].dis1;
	}
	int Min=99999999;
	for(int i=0;i<=n;i++){
		Min=min(Min,f[i]);
	}
	cout<<Min;
	return 0;
}
