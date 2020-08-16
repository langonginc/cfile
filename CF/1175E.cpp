#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[500005],b[500005][40];
int l,r;

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d", &l,&r);
    a[l]=max(a[l],r);
  }
  b[0][0]=a[0];
  for(int i = 1;i <500005;i++){
    a[i]= max(a[i], a[i-1]);
    b[i][0]= a[i];
  }
  for(int j=0;j<20;j++){
    for(int i=1;i<=500005;i++)
    {
      b[i][j]=b[b[i-1][j-1]][j-1];
    }
  }
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d", &l,&r);
    int ans = 0;
    for(int j=19;j>=0;j--)
    {
      if(b[l][j]<r)
      {
        ans+=(1<<j);
        l=b[l][j];
      }
      if(b[l][0]>=r)
        printf("%d\n", ans+1);
      else
        printf("%d\n", -1);
    }
  }
}
