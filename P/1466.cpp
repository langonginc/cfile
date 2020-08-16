#include<iostream>
#include<cstdio>
#define sum(x) ((1+(x))*(x)>>1)
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long ll;
ll n,dp[50][1005],c,m;
int main(){
    scanf("%lld",&n);
    m=sum(n);
    if(m&1){
        printf("0\n");
        return 0;
    }
    c=m>>1,dp[1][1]=1,dp[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(j<i){//j<i
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j]+dp[i-1][j-i]);
            }
        }
    }
    printf("%lld\n",(dp[n][c]>>1));
    return 0;
}