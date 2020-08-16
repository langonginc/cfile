#include<iostream>
#include<stdio.h>
#include<deque>
#define max(_1,_2) ((_1)>(_2)?(_1):(_2))
#define min(_1,_2) ((_1)>(_2)?(_1):(_2))
using namespace std;
struct cr{
	int num,id;
	inline void put(int _num,int _id){
		num=_num,id=_id;
	}
}a[1000005];
int num,n,m;
void work(int _if_min){
	deque<cr>q;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&q.back().num*_if_min>=a[i].num*_if_min){
			q.pop_back();
		}
		q.push_back(a[i]);
		if(q.front().id==i-m){
			q.pop_front();
		}
		if(i>=m)printf("%d\n",q.front().num);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		a[i].put(num,i);
	}
	work(-1);
	return 0;
}
