#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct peo{
    int get,eat;
    bool operator<(const peo & _)const{
        return eat>_.eat;
    }
};
int n,dp[220][220*220],sum[220];
peo a[205];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].get,&a[i].eat);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i].get;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum[i];j++){
            if(j>=a[i].get){
                dp[i][j]=min(dp[i][j],max(dp[i-1][j-a[i].get],j+a[i].eat));
            }
            else{
                dp[i][j]=min(dp[i][j],max(dp[i-1][j],sum[i]-j+a[i].eat));
            }
        }
    }
    int ans=2147483646;
    for(int i=0;i<=sum[n];i++){
        ans=min(ans,dp[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}