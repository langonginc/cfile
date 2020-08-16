#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  long long n,m,x,ans;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>x;
    ans=max(ans,x);
  }
  cout<<n*ans;
}
