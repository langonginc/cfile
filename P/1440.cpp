#include<iostream>
using namespace std;
#include<cstdio>
#include<deque>
struct node{
	int num,id;
	inline void in(int num_,int id_){
		num=num_,id=id_;
	}
};
int main(){
	int n,m,a;
	scanf("%d%d",&n,&m);
	deque<node>q;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&i-q.front().id>m){
			q.pop_front();
		}
		if(q.empty()){
			printf("0\n");
		}
		else{
			printf("%d\n",q.front().num);
		}
		scanf("%d",&a);
		node t;
		t.in(a,i);
		while(!q.empty()&&q.back().num>a){
			q.pop_back();
		}
		q.push_back(t);
	}
	return 0;
}
