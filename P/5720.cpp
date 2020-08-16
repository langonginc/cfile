#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
  long long a,ans=0;
  cin>>a;
  while(a!=1)
  {
    a>>=1,ans++;
  }
  cout<<ans+1;
  return 0;
}

