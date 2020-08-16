#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
void f(int root);
const int INF=INT_MAX;
const int inf=6005;
vector<int>adj[inf];
int n,r[inf],teacher_boss[inf],Teacher_Boss,dp[inf][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	int a,b;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		adj[b].push_back(a);
		teacher_boss[a]++;
	}
	scanf("%d%d",&a,&b);
	for(int i=1;i<=n;i++){
		if(teacher_boss[i]==0){
			Teacher_Boss=i;
			break;
		}
	}
	f(Teacher_Boss);
	cout<<max(dp[Teacher_Boss][0],dp[Teacher_Boss][1])<<endl;
	return 0;
}
void f(int root){
	dp[root][0]=0;
	dp[root][1]=r[root];
	for(int i=0;i<adj[root].size();i++){
		int v=adj[root][i];
		f(v);
		dp[root][0]+=max(dp[v][0],dp[v][1]);
		dp[root][1]+=dp[v][0];
	}
	return ;
}
