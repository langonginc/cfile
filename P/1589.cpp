namespace scope{
	using namespace std;
	struct node{
		int start,end;
		bool operator<(const node &_)const{
			return start<_.start;
		}
	};
	inline void maxer(int &u,int _){
		u=u>_ ?u:_;
	}
	inline void miner(int &u,int _){
		u=u<_ ?u:_;
	}
	#define max(_,__) ((_)>(__) (_):(__))
	#define min(_,__) ((_)<(__) (_):(__)) 
	int n,k,x,ans;
	node a[100005];
}
#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace scope;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;scanf("%d%d",&a[i].start,&a[i].end),i++);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		maxer(x,a[i].start);
		while(x<a[i].end){
			x+=k,ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
