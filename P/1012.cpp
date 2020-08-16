#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
namespace scope{
	using namespace std;
	typedef long long ll;
	int n;
	string s[25];
	bool cmp(string s1,string s2){
		return s1+s2>s2+s1;
	}
}
using namespace scope;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++){
    	cout<<s[i];
	}
    return 0;
}
