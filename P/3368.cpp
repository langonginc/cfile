#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,q,type,x,y,s,a[500001],tree[500001];
ll lowbit(ll num){
    return num&-num;
}
void add(ll s,ll num){
    for(ll i=s;i<=n;i+=lowbit(i)) tree[i]+=num;
}
ll ask(ll s){
    ll ans=0;
    for(ll i=s;i>=1;i-=lowbit(i)) ans+=tree[i];
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=q;i++){
        scanf("%lld",&type);
        if(type==1){
            scanf("%lld%lld%lld",&x,&y,&s);
            add(x,s);
            add(y+1,-s);
        }
        if(type==2){
            scanf("%lld",&x);
            printf("%lld\n",a[x]+ask(x));
        }
    }
}
