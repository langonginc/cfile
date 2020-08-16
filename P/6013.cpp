#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll c[1000005],money,ans,n;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int t;
        ll x,day;
        money+=c[i];
        scanf("%d",&t);
        if(t==1){
            scanf("%lld",&x);
            money+=x;
        }
        if(t==2){
            scanf("%lld",&x);
            money-x>=0 ?money-=x :ans++;
        }
        if(t==3){
            scanf("%lld%lld",&x,&day);
            c[day]+=x,money-=x;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
