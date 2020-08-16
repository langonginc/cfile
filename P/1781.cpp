#include<iostream>
#include<cstdio>
#include<cstring>
namespace scope{
	using namespace std;
	int n,id,size1,size2;
	typedef long long ll;
	string maxx,s;
}
using namespace scope;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cin>>s;
        size1=s.size(),size2=maxx.size();
        if(size1>size2 || (size1>=size2 && s> maxx)){
            maxx=s,id=i;
        }
    }
    cout<<id<<endl<<maxx<<endl;
    return 0;
}
