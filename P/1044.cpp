/*
5+1 On Luogu-P1044-栈
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll h[30], n;

int main ()
{
  scanf ("%lld",&n);
  if(n>30)printf("ILE\n");
  h[0]=h[1]=1;
  for (int i=2; i<= n; i++)
  {
    for (int j=0; j< i; j++)
    {
      h[i]+= h[j]* h[i-j-1];
    }
  }
  printf("%lld",h[n]);
  return 0;
}
