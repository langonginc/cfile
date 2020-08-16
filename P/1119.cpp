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
const int inf=100005;
//struct edge{
//	int pos,dis;
//};
//struct node{
//	int pos,dis;
//	bool operator<(const node& a)const{
//		return dis>a.dis;
//	}
//};
int n,m,q,ph[5000][5000],t[inf];
void flo(int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ph[i][j]=min(ph[i][j],ph[i][k]+ph[k][j]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	int a,b,v;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			ph[i][j]=INF;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&v);
		ph[a][b]=v;
		ph[b][a]=v;
	}
	scanf("%d",&q);
	int now=0;
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&v);
		while(t[now]<=v&&now<n){
			flo(now++);
		}
		if(t[a]>v||t[b]>v){
			cout<<"-1"<<endl;
		}
		else if(ph[a][b]>=INF){
			cout<<"-1"<<endl;
		}
		else{
			cout<<ph[a][b]<<endl;
		}
	}
	return 0;
}
