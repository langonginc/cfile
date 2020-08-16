#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int n;
map<string,short> mp;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string a;
    cin>>a;
    mp[a]=1;
  }
  for(int i=0;i<n;i++)
  {
    string b;
    cin>>b;
    mp[b]=2;
  }
  //...
}
