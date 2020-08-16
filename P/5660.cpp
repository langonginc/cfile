#include<iostream>
using namespace std;
int main(){
	char a;
	int ans=0;
	while(cin>>a){
		if(a-'0'==1)ans++;
	}
	cout<<ans;
	return 0;
}
