#include<iostream>
#include<cstdio>
#include<cstring>
#define debug 0
using namespace std;
int fetch(char x){
    if(x=='w')return 0;
    if(x=='b')return 1;
    else      return 2;
}
#define max(x,y) ((x)>(y)?(x):(y))
int n,a[355],ans,b,r,w;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        a[i]=a[i+n]=fetch(x);
        if(a[i]==0)w++;
        if(a[i]==1)b++;
        if(a[i]==2)r++;
    }
    if(w>=n || b>=n || r>=n){
        printf("%d",n);
        return 0;
    }
    if(debug){
        for(int i=1;i<=2*n;i++)
            printf("%d",a[i]);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        int now=0;
        if(a[i]==1){//front blue
            for(int j=i;j>0;j--){
                if(a[j]==1 || a[j]==0){
                    now++;
                }
                else{
                    break;
                }
            }
        }
        else if(a[i]==2){//front red
            for(int j=i;j>0;j--){
                if(a[j]==2 || a[j]==0){
                    now++;
                }
                else{
                    break;
                }
            }
        }
        else{//front whtie
            int lblue=0,lred=0;
            for(int j=i;j>0;j--){
                if(a[j]==1 || a[j]==0){
                    lblue++;
                }
                else{
                    break;
                }
            }
            for(int j=i;j>0;j--){
                if(a[j]==2 || a[j]==0){
                    lred++;
                }
                else{
                    break;
                }
            }
            now+=max(lblue,lred);
        }
        if(a[i+1]==1){//back blue
            for(int j=i+1;j<=n+i;j++){
                if(a[j]==1 || a[j]==0){
                    now++;
                }
                else{
                    break;
                }
            }
        }
        else if(a[i+1]==2){//back red
            for(int j=i+1;j<=n+i;j++){
                if(a[j]==2 || a[j]==0){
                    now++;
                }
                else{
                    break;
                }
            }
        }
        else{//back whtie
            int rblue=0,rred=0;
            for(int j=i+1;j<=n+i;j++){
                if(a[j]==1 || a[j]==0){
                    rblue++;
                }
                else{
                    break;
                }
            }
            for(int j=i+1;j<=n+i;j++){
                if(a[j]==2 || a[j]==0){
                    rred++;
                }
                else{
                    break;
                }
            }
            now+=max(rblue,rred);
        }
        ans=max(ans,now);
    }
    printf("%d\n" ,(ans<n?ans:n));
    return 0;
}