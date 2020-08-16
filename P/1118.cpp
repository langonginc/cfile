#include<iostream>
#include<cstdlib>
using namespace std;
int n,s,a[10000],c,b[10000];
bool d[10000];
int f(int x){
    int p=1;
    for(int i=1;i<=x;i++){
        p*=i;
    }
    return p;
}
int cm(int a,int b){
    return f(a)/(f(b)*f(a-b));
}
void tr(int k){
    if(k>n){
        if(c==s){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            exit(0);
        }
    }
    else{
        for(int i=1;i<=n&&c+a[k]*i<=s;++i){
            if(!d[i]){
                c+=b[k]*i;
                d[i]=true;
                a[k]=i;
                tr(k+1);
                a[k]=0;
                d[i]=false;
                c-=b[k]*i;
            }
        }
    }
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        b[i]=cm(n-1,i-1);
    }
    c=0;
    tr(1);
    return 0;
}
