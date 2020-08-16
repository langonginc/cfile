#include<iostream>
#include<cstdio>
#include<stack>
namespace scope{
	using namespace std;
	const int inf=1e5+5;
	struct cow{
		int num,h;
	};
	cow in(int num,int h){
		cow _cow;
		_cow.num=num,_cow.h=h;
		return _cow;
	}
	stack<cow>s;
	int n,high[inf],ans[inf];
}
using namespace scope;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;scanf("%d",&high[i]),i++);
	for(int i=n;i>=1;i--){
		while(!s.empty()&&s.top().h<=high[i])s.pop();
		if(s.empty())ans[i]=0;
		else ans[i]=s.top().num;
		s.push(in(i,high[i]));
	}
	for(int i=1;i<=n;printf("%d\n",ans[i]),i++);
	return 0;
}
