#include<iostream>
#include<cstdio>
#include<cstring>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long ll;
ll v,n,a[50],dp[20005];
int main(){
    scanf("%lld%lld",&v,&n);
    for(int i=1;i<=v;i++){
        scanf("%lld",&a[i]);
    }
    dp[0]=1;
    for(int i=1;i<=v;i++){
        for(int j=a[i];j<=n;j++){
            dp[j]=dp[j]+dp[j-a[i]];
        }
    }
    printf("%lld",dp[n]);
    return 0;
}