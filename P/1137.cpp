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
int n,m,du[inf],f[inf]; 
vector<int>adj[inf];
void tuopu(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			q.push(i);
			f[i]=1; 
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<adj[x].size();i++){
			int y=adj[x][i];
			du[y]--;
			f[y]=max(f[y],f[x]+1);
			if(du[y]==0){
				q.push(y);
			}
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		du[y]++;
	}
	tuopu();
	for(int i=1;i<=n;i++){
		cout<<f[i]<<endl;
	}
	return 0;
} 
