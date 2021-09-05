#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 105;
string str;
int num[inf];

int main ()
{
    cin >> str;
    int len = str.length();
    int numlen = 0;
    for (int i = 0; i < len; i ++)
    {
        if (str[i] == '.')
        {
            if (str[i + 1] - '0' >= 5)
            {
                num[i - 1] ++;
                num[i - 2] += num[i - 1] / 10;
                num[i - 1] %= 10;
            }
            numlen = i;
            break;
        }
        num[i] = str[i] - '0';
    }
    if (numlen == 0) numlen = len;
    long long sum = 1;
    for (int i = 0; i < numlen; i ++)
    {
        // printf ("[] num[%d]=%d sum=%lld\n", i, num[i], sum);
        sum = (sum * num[i]) % 10007;
    }
    cout << sum << endl;
    return 0;
}