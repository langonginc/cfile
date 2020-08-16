#include<iostream>
#include<cstdio>
using namespace std;
int n,money,ordermoney[200],result;
bool used[200];
void order_(int usedmoney,int whichfood){
	if(usedmoney>money){
		return;
	}
	else if(usedmoney==money){
		result++;
	}
	else{
		for(int i=whichfood;i<=n;i++){
			if(used[i]==false){
				used[i]=true;
				order_(usedmoney+ordermoney[i],i+1);
				used[i]=false;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&money);
	for(int i=1;i<=n;i++){
		cin>>ordermoney[i];
	}
	order_(0,1);
	cout<<result;
	return 0;
}
