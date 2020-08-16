#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double ans=0x10f,data=0.00,x[20],y[20];
bool eat[20];
void dfs(int the,int floor){
	if(data>ans){
		return;
	}
	if(the>n){
		ans=min(data,ans);
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!eat[i]){
				eat[i]=true;
				data+=sqrt((x[floor]-x[i])*(x[floor]-x[i])+(y[floor]-y[i])*(y[floor]-y[i]));
				dfs(the+1,i);
				data-=sqrt((x[floor]-x[i])*(x[floor]-x[i])+(y[floor]-y[i])*(y[floor]-y[i]));
				eat[i]=false;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&y[i],&x[i]);
	}
	dfs(1,0);
	printf("%.2f",ans);
	return 0;
}
