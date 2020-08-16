#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline void check(int num, int sum)
{
  switch (num) {
    case 0:printf("%d %d %d",sum,sum,sum);break;
    case 1:printf("%d %d %d",sum-1,sum-1,sum-1+5);break;
    case 2:printf("%d %d %d",sum-1,sum-1+1,sum-1+4);break;
    case 3:printf("%d %d %d",sum,sum,sum+1);break;
    case 4:printf("%d %d %d",sum,sum+1,sum);break;
    case 5:printf("%d %d %d",sum-1,sum-1+1,sum-1+5);break;
    case 6:printf("%d %d %d",sum,sum,sum+2);break;
    case 7:printf("%d %d %d",sum,sum+1,sum+1);break;
    case 8:printf("%d %d %d",sum,sum+2,sum);break;
    case 9:printf("%d %d %d",sum,sum,sum+3);break;
    case 10:printf("%d %d %d",sum,sum+1,sum+2);break;
    case 11:printf("%d %d %d",sum,sum+2,sum+1);break;
    case 12:printf("%d %d %d",sum,sum,sum+4);break;
    case 13:printf("%d %d %d",sum,sum+1,sum+3);break;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  switch(n){
    case 1: printf("-1");return 0;
    case 2: printf("-1");return 0;
    case 5: printf("-1");return 0;
}
  // if(n==1 || n==2 || n==5)
  //   printf("-1");
  int sum=n/14;
  int lst=n%14;
  check(lst,sum);
  return 0;
}
