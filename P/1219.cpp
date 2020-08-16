#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,ans;
int queen[10000],ob1[10000],ob2[10000],result[10000];
void eight(int x){
	if(x>n){
		ans++;
		if(ans<=3){
			for(int i=1;i<=n;i++){
				printf("%d ",result[i]);
			}
			printf("\n");
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(queen[i]==0&&ob1[i-x+n]==0&&ob2[i+x]==0){
				result[x]=i;
				queen[i]=1;
				ob1[i-x+n]=1;
				ob2[i+x]=1;
				eight(x+1);
				ob1[i-x+n]=0;
				ob2[i+x]=0;
				queen[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	eight(1);
	printf("%d",ans);
	return 0;
}
