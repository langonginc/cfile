#include<iostream>
#include<cstdio>
using namespace std;
int s[20][20],ans,a,b;
void dfs(int x,int y)
{
  int i;
  if (x==a&&y==b) {
    ans++;return;
  }
  else if (s[x][y]!=-1)
  {
    dfs(x,y+1);
    dfs(x+1,y);
  }
}
int main()
{
   int n,x1,x2;
   scanf("%d%d%d",&a,&b,&n);
   for(int i=1;i<=n;i++)
   {
     scanf("%d%d",&x1,&x2);
     s[x1][x2]=-1;
   }
   for(int i=1;i<=a;i++)
      s[i][b+1]=-1;
   for(int i=1;i<=b;i++)
      s[a+1][i]=-1;
   dfs(1,1);
   printf("%d\n",ans);
   return 0;
}
