#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#include<cstdlib> 
using namespace std;
struct node{
	int a;
	bool operator<(const node &b)const{
		return a>b.a;
	}
};
int n;
int main(){
	
//	priority_queue<node>q;
	scanf("%d",&n);
	priority_queue <node> q;
	for(int i=0;i<n;i++)
	{
		node x;
		scanf("%d",&x.a);
		q.push(x);
	}
	int ans=0;
	while(q.size()>1){
		node d=q.top();
		q.pop();
		node y=q.top();
		q.pop();
		ans=ans+d.a+y.a;
		node s;
		s.a=d.a+y.a;
		q.push(s);
	}
	cout<<ans;
}
