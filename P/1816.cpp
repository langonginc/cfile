#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;
//const int INF=INT_MZX;
int n,m,st[100005][30],lg[100005];
int checkst(int left,int right){
	int k=lg[right-left+1]-1;
	return min(st[left][k],st[right-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&st[i][0]);
	}
	for(int i=1;i<20;i++){
		for(int j=1;(1<<i)+j-1<=n;j++){
			st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		lg[i]=lg[i-1]+((1<<lg[i-1])==i);
	}
	int left,right;
	for(int i=0;i<m;i++){
		scanf("%d%d",&left,&right);
		printf("%d ",checkst(left,right));
	}
	return 0;
}
