// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// typedef long long ll;
//
// bool a[1000000005];
// int pc, prime[100000005];
//
// void pt (ll inf)
// {
//     for (int i = 1; i < inf; i ++)
//     {
//         a[i] = 1;
//     }
//     for (int i = 1; i < inf; i ++)
//     {
//         if (a[i])
//         {
//             prime[pc ++] = i;
//         }
//         for (int j = 0; j < pc && i * prime[j] < inf; j ++)
//         {
//             a[i*prime[j]] = 0;
//             if(i % prime[j] == 0)
//             {
//                 break;
//             }
//         }
//     }
// }
//
// int main ()
// {
//     ll x;
//     bool first = true;
//     cin >> x;
//     pt (x + 2);
//     printf ("%d=", x);
//     for (int i = 1; i < pc && x >= 1; i ++)
//     {
//         while (x % prime[i] == 0)
//         {
//             if (!first)
//             {
//                 printf ("*");
//             }
//             else
//             {
//                 first = false;
//             }
//             printf ("%d", prime[i]);
//             x /= prime[i];
//         }
//     }
//     printf ("\n");
//     return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <cmath>
// using namespace std;
// typedef long long ll;
//
// int main ()
// {
//     ll n, x;
//     bool first = true;
//     cin >> n;
//     printf ("%d=", n);
//     x = n;
//     bool flag = true;
//     for (int i = 2; i <= sqrt(n); i ++)
//     {
//         if (n % i == 0)
//         {
//             flag = false;
//             break;
//         }
//     }
//     if (flag)
//     {
//         printf ("%d", n);
//         return 0;
//     }
//     for (int i = 2; i <= n && x > 1; i ++)
//     {
//         while (x % i == 0)
//         {
//             if (!first)
//             {
//                 printf ("*");
//             }
//             else
//             {
//                 first = false;
//             }
//             printf ("%d", i);
//             x /= i;
//         }
//     }
//     printf ("\n");
//     return 0;
// }

#include <iostream>
using namespace std;
int main(){
    int n, i = 2;
    cin>> n;
    cout<< n<< "=";
    while(n != 1){
        while(n % i == 0 ){
            if(n == i){
                cout<< i;
            }else{
                cout<< i<< "*";
            }
            n= n/ i;
        }
        i++;
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main ()
{
    ll x;
    bool first = true;
    cin >> x;
    printf ("%d=", x);
    for (int i = 2; i <= x && x >= 1; i ++)
    {
        while (x % i == 0)
        {
            if (!first)
            {
                printf ("*");
            }
            else
            {
                first = false;
            }
            printf ("%d", i);
            x /= i;
        }
    }
    printf ("\n");
    return 0;
}
*/

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <cmath>
// using namespace std;
// typedef long long ll;
//
// int main ()
// {
//     ll x;
//     bool first = true;
//     cin >> x;
//     printf ("%d=", x);
//     for (int i = 2; i <= sqrt(x) && x >= 1; i ++)
//     {
//         while (x % i == 0)
//         {
//             if (!first)
//             {
//                 printf ("*");
//             }
//             else
//             {
//                 first = false;
//             }
//             printf ("%d", i);
//             x /= i;
//         }
//     }
//     printf ("\n");
//     return 0;
// }


// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// typedef long long ll;
//
// int main ()
// {
//     int x;
//     bool first = true;
//     cin >> x;
//     printf ("%d=", x);
//     int j = 2;
//     while (x >= 1)
//     {
//         if (x % j == 0)
//         {
//             if (!first)
//             {
//                 printf ("*");
//             }
//             else
//             {
//                 first = false;
//             }
//             printf ("%d", j);
//             x /= j;
//         }
//         else j ++;
//     }
//     printf ("\n");
//     return 0;
// }

// #include<iostream>
// using namespace std;
// #include<cstdio>
// int n;
// int main(){
//     scanf("%d",&n);
//     int f = true;
//     printf ("%d=",n);
//     for(int i=2;i<=n;i++){
//         for(int j=2,x=i;j<=i;j++){
//             while(x%j==0){
//                 if (f) f = false;
//                 else printf ("*");
//                 x/=j;
//                 printf ("%d", j);
//             }
//             n=x;
//         }
//     }
//     return 0;
// }
