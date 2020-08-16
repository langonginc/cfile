#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100001],m,r[100001],g[100001],t=0,tim=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    for(int i=1;i<=n;i++)scanf("%d",&g[i]);
    tim=m;
    for(int i=1;i<=n;i++)
    {
        t+=tim;
        int ce=r[i]+g[i];
        tim=t%ce;
        if(g[i]<tim)t+=(ce-tim);
        tim=a[i];
        printf("%d\n",t);
    }
    return 0;
} 