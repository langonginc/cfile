#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
void swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}
struct pos
{
    int x,y;
    void s()
    {
        if(x>y)swap(x,y);
    }
    bool operator<( pos &a)
    {
        if(x!=a.x)
            return x<a.x;
        else
        {
            if(y<a.y)
            {
                swap(a.x,a.y);
                return true;
            }
            else
            {
                swap(x,y);
                return false;
            }
        }
    }
}a[1000005];
int n,ans;
int main(){
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        // a[i].s();
        if(a[i].x>a[i].y){
            // cout<<"#";
            swap(a[i].x,a[i].y);
            // printf("%d %d\n",a[i].x,a[i].y);
        }
    }    
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d %d\n",a[i].x,a[i].y);
    // }
    int num=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i].x==num)
        {
            ans++;
        }
        else if(a[i].x!=a[i-1].x)
        {
            break;
        }
        num++;
    }
    printf("%d\n",ans);
    return 0;
}
