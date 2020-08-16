using namespace std;
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
const int  N=1e5+5;
const int  M=1e5*5+5;
vector<int>adj[N];
vector<int>a[M];
queue<int>q;
priority_queue<int>qq;
int n,m,du[N];
inline void clean(){
	for(int i=0;i<=n+1;i++){
		du[i]=0;
		adj[i].clear();
	}
}
void make(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<a[i].size();j++){
			adj[a[i][j-1]].push_back(a[i][j]);
			du[a[i][j]]++;
		}
	}
}
bool tp(int x){
	int g=0;
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			q.push(i);
			g++;
		}
	}
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(int i=0;i<adj[h].size();i++){
			du[adj[h][i]]--;
			if(du[adj[h][i]]==0){
				q.push(adj[h][i]);
				g++;
			}
		}
	}
//	cout<<g<<" ";
	return g==n;
}
int main(){
	int k,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
//	make(2);
//	cout<<tp(2);
//	return 0;
	int left=1,right=n,ans=0,mid;
	while(left<=right){
		mid=(left+right)>>1;
		clean();
		make(mid);
		if(tp(mid)){
			ans=mid;
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
//	cout<<ans<<endl;
	clean();
	make(ans);
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			qq.push(-i);
		}
	}
	while(!qq.empty()){
		int h=-qq.top();
		qq.pop();
		printf("%d ",h);
		for(int i=0;i<adj[h].size();i++){
			du[adj[h][i]]--;
			if(du[adj[h][i]]==0){
				qq.push(-adj[h][i]);
			}
		}
	}
	return 0;
}
