#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 10005;

class BigNumber
{
    public:
    int number[inf];
    int len;
    BigNumber ()
    {
        len = 0;
    }
    BigNumber (int _x)
    {
        len = 0;
        while (_x > 0)
        {
            number[++ len] = _x % 10;
            _x /= 10;
        }
    }
    // BigNumber (BigNumber &x)
    // {
    //     for (int i = 1; i <= x.len; i ++)
    //     {
    //         number[i] = x.number[i];
    //     }
    //     len = x.len;
    // }
    void clear (int n)
    {
        for (int i = 0; i <= n; i ++) number[i] = 0;
        len = 0;
    }
    void tomax (int n)
    {
        for (int i = 1; i <= n; i ++) number[i] = 9;
        len = n;
    }
    int & operator [] (int index)
    {
        return number[index];
    }
    bool operator < (BigNumber &x)
    {
        if (len != x.len) return len < x.len;
        for (int i = len; i > 0; i --)
        {
            if (number[i] != x.number[i]) return number[i] < x.number[i];
        }
        return false;
    }
    BigNumber operator + (BigNumber const x) const
    {
        int newlen = max (len, x.len);
        BigNumber ans;
        ans.clear (newlen + 5);
        for (int i = 1; i <= newlen; i ++)
        {
            if (i <= len) ans[i] += number[i];
            if (i <= x.len) ans[i] += x.number[i];
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
        }
        if (ans.number[newlen + 1]) newlen ++;
        ans.len = newlen;
        return ans;
    }
    void operator = (BigNumber x)
    {
        for (int i = 1; i <= x.len; i ++)
        {
            number[i] = x.number[i];
        }
        len = x.len;
    }
    BigNumber operator * (BigNumber const &x)
    {
        BigNumber ans;
        ans.clear (len + x.len + 5);
        for (int i = 1; i <= len; i ++)
        {
            int carry=0;
            for (int j = 1; j <= x.len; j ++) 
            {
                ans[i + j - 1] += number[i] * x.number[j] + carry;
                carry = ans[i + j - 1] / 10;
                ans[i + j - 1] %= 10;
            }
            ans[i + x.len] += carry;
        }
        int newlen = len + x.len + 2;
        while (ans[newlen] == 0 && newlen > 0) 
        {
            newlen --;
        }
        ans.len = newlen;
        return ans;
    }
    BigNumber operator / (int &x)
    {
        BigNumber ans;
        ans.clear (len + 5);
        int base = 0;
        for (int i = len; i > 0; i --)
        {
            base = base * 10 + number[i];
            ans[i] = base / x;
            base %= x;
        }
        int newlen = len;
        while (ans[newlen] == 0 && newlen > 0) 
        {
            newlen --;
        }
        ans.len = newlen;
        return ans;
    }
};

class Node
{
    public:
    int a, b;
    bool operator < (const Node &x) const
    {
        return a * b < x.a * x.b;
    }
} a[inf];

int n;

BigNumber s (1), tmp (0), ans (0);

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i <= n; i ++)
    {
        scanf ("%d%d", &a[i].a, &a[i].b);
    }
    sort (a + 1, a + n + 1);
    // ans.tomax (inf - 5);
    for (int i = 0; i <= n; i ++)
    {
        tmp = s / a[i].b;
        if (ans < tmp) ans = tmp;
        BigNumber etmp (a[i].a);
        s = s * etmp;
	}
    for (int i = ans.len; i > 0; i --)
    printf ("%d", ans[i]);
    return 0;
}