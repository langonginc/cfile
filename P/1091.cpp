#include<iostream>
#include<cstdio>
using namespace std;
int n,hight[105],left_[105],right_[105],add[105],maxvalue,maxsub,maxnumber;
int result1,result2,endresult,used[105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&hight[i]);
	}
	for(int i=n-1;i>0;i--){//left side(down), start
		for(int j=n;j>=i+1;j--){//finsh
			if(hight[i]>hight[j]&&left_[i]<left_[j]+1){
				left_[i]=left_[j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){//left side(down), start
		for(int j=1;j<=i-1;j++){//finsh
			if(hight[i]>hight[j]&&right_[i]<right_[j]+1){
				right_[i]=right_[j]+1; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		add[i]=left_[i]+right_[i];
		if(maxvalue<add[i]){
			maxvalue=add[i];
		}
	}
	printf("%d",n-maxvalue-1);
	return 0;
}
