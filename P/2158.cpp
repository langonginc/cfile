#include<iostream>
#include<cstdio>
using namespace std;
#define run(type_class,type,start,end) for(type_class type=start;type<=end;type++)
typedef long long ll;
const ll MAXN=40011;

ll phi_(ll n)
{
  ll ans=n;
  for(ll i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      ans=ans/i*(i-1);
      // for(;n%i==0;n/=i);
      while(n%i==0)n/=i;
    }
  }
  if(n>1)
  {
    ans=ans/n*(n-1);
  }
  return ans;
}

ll phi[40011],primes[40011],tot,n;

// void eulerTable()
// {
//   phi[1]=1;
//   for (int i = 2; i < n; ++i)
//   {
//     if(phi[i] == 0)
//     {
//       phi[i] = i-1;primes[tot++] = i;
//     }
//     for (int j = 0; j < tot && i * primes[j]<n; ++j) {
//       if(i % primes[j] == 0){
//         phi[i*primes[j]] = phi[i] * primes[j];break;
//       }
//       else {
//         phi[i*primes[j]] = phi[i] * (primes[j]-1);
//       }
//     }
//   }
// }

int main()
{
  ll ans=0;

  scanf("%lld",&n);
  for(int i=2;i<=n-1;++i){
    ans+=phi_(i);
  }
  printf("%lld",n==1?0:ans*2+3);
  return 0;
}
