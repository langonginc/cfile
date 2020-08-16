#include<iostream>
#include<cstdio>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
int n,a[1000005],card[15],sum,ans;
int main(){
    scanf("%d" ,&n);
    for(int i=1;i<=n;i++){
        scanf("%d" ,&a[i]);
        sum+= a[i];
        card[a[i]]++;
    }
    for(int i= 1;i<= 10;i++){//chose each 2 cards
        if(card[i]>=2 && (sum-i-i)%10 ==0){
            ans= ((i+i) %10 ==0) ?10 :max(ans, (i+i) %10);
        }
    }
    for(int i= 1;i<= 10;i++){
        for(int j= 1;j<= 10;j++){//chose each 1 card
            if(i!=j && card[i]>=1 && card[j]>=1 && (sum-i-j)%10 ==0){ // }
                ans= ((i+j) %10 ==0) ?10 :max(ans, (i+j) %10);
            }
        }
    }
    printf("%d\n" ,ans);
    return 0;
}
