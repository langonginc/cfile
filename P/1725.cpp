#include<iostream>
using namespace std;
#include<cstdio>
#include<deque>
const int N=200005;
struct node{
	int num,id;
	inline void in(int num_,int id_){
		num=num_,id=id_;
	}
};
int num[N],dp[2*N];
deque<node>q;
//int max(int left,int right,int i){
//	while(!q.empty()&&q.front().id<i-right){
//		cout<<q.front().num<<"ERR"<<endl;;
//		q.pop_front();
//	}
//	int a=dp[i-left];
//	node t;
//	t.in(a,i-left);
//	while(!q.empty()&&q.back().num<a){
//		cout<<q.back().num<<"out; in";
//		q.pop_back();
//	}
//	q.push_back(t);
//	cout<<i<<"lb"<<q.back().num<<endl;
//	return q.front().num;
//}
int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<=n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=l;i<=n+l;i++){
		while(!q.empty()&&q.front().id<i-r){
//			cout<<q.front().num<<"ERR"<<endl;;
			q.pop_front();
		}
		int a=dp[i-l];
		node t;
		t.in(a,i-l);
		while(!q.empty()&&q.back().num<a){
//			cout<<q.back().num<<"out; in";
			q.pop_back();
		}
		q.push_back(t);
//		cout<<i<<"lb"<<q.back().num<<endl;
		dp[i]=num[i]+q.front().num;
//		cout<<dp[i]<<"jip"<<endl;
	}
	int rj=0;
	for(int i=n;i<=n+l;i++){
		rj=max(rj,dp[i]);
//		cout<<dp[i]<<endl;
	} 
	cout<<rj<<endl;
	return 0;
}
