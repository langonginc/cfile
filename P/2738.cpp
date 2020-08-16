#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#include<cstdlib> 
#include<set>
#include<vector> 
#include<climits>
using namespace std;
typedef const int const_int_2;
const_int_2 INF=INT_MAX/3;
const int inf=200;
struct edge{
	int edgenum;
	int dis;
	int left;
	int right;
	set<int>setleft;	
	set<int>setright;
}fence[inf];
int n,d[inf][inf],a[inf][inf],maxvalue=1;
int main(){
	scanf("%d",&n);
	int num,dis,x,y,z;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&fence[i].edgenum,&fence[i].dis,&x,&y);
		fence[i].left=fence[i].right=0;
		for(int j=1;j<=x;j++){
			scanf("%d",&z);
			fence[i].setleft.insert(z);
		}		
		for(int j=1;j<=y;j++){
			scanf("%d",&z);
			fence[i].setright.insert(z);
		}
		for(int j=1;j<i;j++){
			if(fence[j].setleft.find(fence[i].edgenum)!=fence[j].setleft.end()){
				if(fence[i].setleft.find(fence[j].edgenum)!=fence[i].setleft.end()){
					fence[i].left=fence[j].left;
				}
				if(fence[i].setright.find(fence[j].edgenum)!=fence[i].setright.end()){
					fence[i].right=fence[j].left;
				}
			}
			if(fence[j].setright.find(fence[i].edgenum)!=fence[j].setright.end()){
				if(fence[i].setleft.find(fence[j].edgenum)!=fence[i].setleft.end()){
					fence[i].left=fence[j].right;
				}
				if(fence[i].setright.find(fence[j].edgenum)!=fence[i].setright.end()){
					fence[i].right=fence[j].right;
				}
			}
			
		}
		if(fence[i].right==0){
			fence[i].right=maxvalue++;
		}
		if(fence[i].left==0){
			fence[i].left=maxvalue++;
		}
		a[fence[i].left][fence[i].right]=d[fence[i].left][fence[i].right]=fence[i].dis;
		a[fence[i].right][fence[i].left]=d[fence[i].right][fence[i].left]=fence[i].dis;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("from%dto%d=%d    ",i,j,d[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]==0){
				a[i][j]=d[i][j]=INF;
			}
		}
	}
	for(int i=0;i<=n;i++){
		a[i][i]=d[i][i]=0;
	}
	int ans=INF;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k-1;i++){
			for(int j=i+1;j<=k-1;j++){
				ans=min(ans,a[i][k]+a[k][j]+d[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
