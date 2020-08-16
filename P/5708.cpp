#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
  double a,b,c,p,ans;
  cin>>a>>b>>c;
  p=(a+b+c)/2;
  ans=sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.1lf",ans);
}

