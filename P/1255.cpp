#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1e4 + 5;

class LargeInt
{
public:
    int number[inf], len;
    LargeInt (int _ch[], int __len)
    {
        for (int i = 0, j = __len - 1; i < __len; i ++, j --)
        {
            number[j] = _ch[i];
        }
        len = __len;
    }
    LargeInt (int x) { len = 1, number[0] = x; }
    LargeInt (){ len = 1, number[0] = 0; }
    LargeInt operator + (LargeInt largeint) const
    {
        LargeInt Result;
        int nowlen = max (len, largeint.len);
        for (int i = 0; i < nowlen; i ++)
        {
            Result.number[i] = number[i] + largeint.number[i];
            Result.number[i + 1] = Result.number[i] / 10;
            Result.number[i] %= 10;
        }
        if (Result.number[nowlen]) Result.len = nowlen + 1;
        else Result.len = nowlen;
        return Result;
    }
};

int empt[1], empt2[1];

int main ()
{
    int n;
    scanf ("%d", &n);
    empt[0] = 1, empt2[0] = 2;
    LargeInt b (empt2, 1), a (empt, 1), f;
    // int a = 1, b = 2, c;
    for (int i = 3; i <= n; i ++)
    {      
        f = a + b;
        a = b, b = f;
    }
    for (int i = f.len - 1; i >= 0; i --)
    {
        printf ("%d", f.number[i]);
    }
    return 0;
}