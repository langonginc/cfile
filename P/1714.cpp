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
int sum[100000000],num[100000000];
int main(){
	int n,m,a;
	scanf("%d%d",&n,&m);
	deque<node>q;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	int ans=-1000000000;
	for(int i=1;i<=n;i++){
		while (!q.empty() && q.front().id < i - m) {
			q.pop_front();
		}
//		if(q.empty()){
//			printf("0\n");
//		}
//		else{
//			printf("%d\n",q.front().num);
//		}
//		scanf("%d",&a);
		a=sum[i];
		node t;
		t.in(a,i);
		ans = max(ans, sum[i] - q.front().num);
		while (!q.empty() && q.back().num >= t.num) {
			q.pop_back();
		}
		q.push_back(t);
		
//		while(!q.empty()&&q.back().num<a){
//			cout<<q.back().num<<"R"<<endl;
//			q.pop_back();
//		}
//		ans=max(ans,sum[i]-sum[q.front().id]);
//		q.push_back(t);
//		cout<<q.back().num<<"I"<<endl;
	}
	cout<<ans;
	return 0;
}
