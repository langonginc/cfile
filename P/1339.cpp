#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#include<vector>
#include<set> 
#include<cstdlib>
using namespace std;
const int M=2147483647;
struct typeV{
	int w;
	int v;
	typeV(int w,int v):w(w),v(v){}
};
struct node{
	int town;
	int dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
vector <typeV> link[20000];
bool used[20000];
int d[20000];
int main(){
	priority_queue<node> q;
	int t,m,ts,te,s,f,v;
	scanf("%d%d%d%d",&t,&m,&ts,&te);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&f,&v);
		link[s].push_back(typeV(v,f));
		link[f].push_back(typeV(v,s));
	}
	node a;
	a.town=ts;
	a.dis=0;
	q.push(a);
	for(int i=1;i <= t;++i){
		d[i]=M;
		used[i]=false;
	}
	d[ts]=0;
	while(!q.empty()){
		a=q.top();
		q.pop();
		int town=a.town;
		int dis=a.dis;
		if(town==te)break;
		if(used[town])continue;
		used[town]=true;
		for(int i=0;i<link[town].size();i++){
			int v=link[town][i].v;
			int w=link[town][i].w;
			if(d[town]+w<d[v]){
				d[v]=d[town]+w;
				node tmp;
				tmp.dis=d[v];
				tmp.town=v;
				q.push(tmp);
			}
		}
	}
	cout<<d[te];
	return 0;
}
