#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 2e4 + 5;
const int fac[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384}; // max: 14

inline bool isnumber (char x)
{
    if (x >= '0' && x <= '9') return true;
    else return false;
}

string breaknumber (int num)
{
    // printf ("BREAK: %d\n", num);
    string ans = "";
    if (num > 2)
    {
        for (int k = 14; k >= 0; k --)
        {
            if (num / fac[k])
            {
                num %= fac[k];
                // ans = ans + "2(" + breaknumber (k) + ")+";
                string subans = breaknumber (k);
                if (subans[0] == '1') ans = ans + "2+";
                else ans = ans + "2(" + subans + ")+";
            }
        }
        ans = ans.substr (0, ans.length () - 1);
    }
    else
    {
        char ch = num + '0';
        ans = ch;
    }
    // cout << "ANS: " << ans << endl;
    return ans;
}

string dfs (string str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i ++)
    {
        if (isnumber (str[i]))
        {
            int num = str[i] - '0', j = i + 1;
            while (isnumber (str[j]))
            {
                num *= 10;
                num += str[j] - '0';
                j ++;
            }
            ans += breaknumber (num);
            i = j - 1;
        }
    }
    return ans;
}

int main ()
{
    string str;
    cin >> str;
    cout << dfs (str);
    return 0;
}