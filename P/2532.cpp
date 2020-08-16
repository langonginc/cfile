/*
5+1 On Luogu-P2532-树屋阶梯
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,prime[10005],cnt,rep[10005],Catalan_number[7000],length;
bool vis[20005];
void multiply(int base,int exponent)
{
  while(exponent--)
  {
    for(int i=1;i<=length;++i)
    {
      Catalan_number[i]*=base;
    }
    for(int i=1;i<=length;++i)
    {
      if(Catalan_number[i]>=10)
      {
        Catalan_number[i+1]+=Catalan_number[i]/10;
        Catalan_number[i]%=10;
        if(i+1>length)
        {
          length++;
        }
      }
    }
  }
}
int factor(int base,int num)
{
	int sum=0;
	while(base)
	{
		base/=num;
		sum+=base;
	}
	return sum;
}
int main()
{
  scanf("%d",&n);
  vis[0]=vis[1]=1;
  cnt=0;
  for(int i=2;i<=2*n;++i)
  {
    if(!vis[i])
      prime[++cnt]=i;
    for(int j=1;j<=cnt&&prime[j]*i<=2*n;++j)
    {
      vis[i*prime[j]]=true;
      if(i%prime[j]==0)
      {
        break;
      }
    }
  }
  for(int i=1;i<=cnt;++i)
  {
    rep[i]=factor(2*n,prime[i])-factor(n,prime[i])-factor(n+1,prime[i]);
  }
  Catalan_number[1]=1;
  length=1;
  for(int i=1;i<=cnt;++i)
  {
    if(rep[i])
    {
      multiply(prime[i],rep[i]);
    }
  }
  for(int i=length;i>=1;i--)
  {
    printf("%d",Catalan_number[i]);
  }
  return 0;
}
