#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,mink,maxk;
double a[105][30],mins=11,maxs=-1,ans[105];
int main()
{

  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    mins=11,maxs=-1;
    for(int j=1;j<=m;j++)
    {
      scanf("%lf",&a[i][j]);
      if(a[i][j]<mins){
        mink=j,mins=a[i][j];
      }
      if(a[i][j]>maxs){
        maxk=j,maxs=a[i][j];
      }
    }
    for(int j=1;j<=m;j++)
    {
      if(j==mink || j==maxk)continue;
      else ans[i]+=a[i][j];
    }
    ans[i]/=(m-2);
  }
  double maxp=-1;
  for(int i=1;i<=n;i++)
  {
    maxp=max(maxp,ans[i]);
  }
  printf("%.2lf",maxp);
  return 0;
}

