#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int t[100005],number[100005],which,ans[100005],result=0,a[300005];
int main(){
	queue <int> nat;

	int time=86400;
	int n;
	scanf("%d",&n);
	memset(ans,0,sizeof(ans));
	which=1;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>number[i];
		for(int j=1;j<=number[i];j++){
			cin>>a[j];
			nat.push(a[j]);
			if(ans[a[j]]==0)result++;
			ans[a[j]]++;
		}
		while(!nat.empty()&&t[which]<=t[i]-time){
			for(int j=1;j<=number[which];j++){
				ans[nat.front()]--;
				if(ans[nat.front()]==0)result--;
				nat.pop();
			}
			which++;
		}
		cout<<result<<endl;
	}
	return 0;
}
