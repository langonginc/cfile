#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std;
class mq{
	struct cr{
		int num,id;
		inline void put(int _num,int _id){
			num=_num,id=_id;
		}
	}a[100000005];
	int work(int _if_min,int st,int n,int m,int result[]){
		int res=0;
		deque<cr>q;
		for(int i=1;i<=n;i++){
			while(!q.empty()&&q.back().num*_if_min>=a[i].num*_if_min) q.pop_back();
			q.push_back(a[i]);
			if(q.front().id==i-m) q.pop_front();
			if(i>=m) result[++res]=q.front().num;
		}
		return res;
	}
	public:
	int minup(int st,int n,int m,int num[],int result[]){
		for(int i=st;i<=n;i++){
			a[i].put(num[i],i);
		}
		return work(1,st,n,m,result);
	}
	int maxup(int st,int n,int m,int num[],int result[]){
		for(int i=st;i<=n;i++){
			a[i].put(num[i],i);
		}
		return work(-1,st,n,m,result);
	}
};
int num[1000005],r[1000005],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	mq b;
	int co=b.minup(1,n,m,num,r);
	for(int i=1;i<=co;i++)printf("%d ",r[i]);
	cout<<endl;
	co=b.maxup(1,n,m,num,r);
	for(int i=1;i<=co;i++)printf("%d ",r[i]);
	return 0;
}
