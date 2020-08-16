#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,k,ans;
int a[50005],vis[50005];
std::vector<int> v;

int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    v.push_back(a[i]);
  }
  for(int i=0;i<n;i++)
  {
    int m=2147483647,x;
    for(int j=0;j<v.size();j++)
    {
      int t=v[j];
      if(t<m)
      {
        m=t;
        x=j;
      }
    }
    v.erase(v.begin()+x);
    if(x!=0)ans++;
  }
  cout<<ans<<endl;
}
