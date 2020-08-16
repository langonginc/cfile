#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int M=2147483647;
int n,point[40],maxV[40][40],position[40][40];
int tree(int left,int right){
	if(maxV[left][right]>0){
		return maxV[left][right];
	}
	if(left==right){
		position[left][right]=left;
		maxV[left][right]=point[left];
	}
	if(left>right){
		return 1;
	}
	if(left<right){
		for(int p=left;p<=right;p++){
			int x=tree(p+1,right)*tree(left,p-1)+point[p];
			if(maxV[left][right]<x){
				maxV[left][right]=x;
				position[left][right]=p;
			}
		}
	}	
	return maxV[left][right];
}
void find(int left,int right){
	if(left>right){
		return;
	}
	else{
		printf("%d ",position[left][right]);
		find(left,position[left][right]-1);
		find(position[left][right]+1,right);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>point[i];
	}
	cout<<tree(1,n)<<endl;
	find(1,n);
	return 0;
}
