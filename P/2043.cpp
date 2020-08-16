#include<iostream>
using namespace std;
#include<cstdio>
int n,a[10005];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for(int j=2,x=i;j<=i;j++){
            while(x%j==0){
                a[j]++,x/=j;
            } 
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]){
            printf("%d %d\n",i,a[i]);
        }
    }
    return 0;
}