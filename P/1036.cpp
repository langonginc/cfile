#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int cnt,sum,k,n,a[25];
bool used[25];
bool prime(int x){
    int i;
    for(i=2;i<=sqrt(x);i++){
        if(x%i==0)
          return false;
    }
    return true;
}
int dfs(int num,int c){
    if(num>k) {
        if(prime(sum))cnt++;
    }
    else{
        for(int i = c; i< n; i++){
            if(!used[i]){
                used[i]=true;
                sum+=a[i];
                dfs(num+1,i+1);
                used[i]=false;
                sum-=a[i];
            }
        }
    }
    return cnt;
}
int main(){
    cin>>n>>k;
    for(int i= 0;i<n;i++)cin>>a[i];
    cout<<dfs(1,0);
    return 0;
}
