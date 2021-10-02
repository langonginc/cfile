#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 35;
int a[inf], b[inf], c[inf];

int main ()
{
    ll na, nb;
    char op;
    int lena = 0, lenb = 0;
    cin >> na >> nb >> op;
    while (na)
    {
        ++ lena;
        if (na & 1) a[lena] = 1;
        na >>= 1; 
    }
    while (nb)
    {
        ++ lenb;
        if (nb & 1) b[lenb] = 1;
        nb >>= 1; 
    }
    for (int i = 32; i >= 1; i --)
    {
        printf ("%d", a[i]);
    }
    printf ("\n");
    for (int i = 32; i >= 1; i --)
    {
        printf ("%d", b[i]);
    }
    printf ("\n");
    for (int i = 32; i >= 1; i --)
    {
        printf ("-");
    }
    printf ("\n");
    for (int i = 32; i >= 1; i --)
    {
        switch (op)
        {
            case '&':
                printf ("%d", a[i] & b[i]);
                break;
            case '|':
                printf ("%d", a[i] | b[i]);
                break;
            case '^':
                printf ("%d", a[i] ^ b[i]);
                break;
        }
    }
    return 0;
}