#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline int get_factor (char a, char b)
{
    int x;
    if (b >= '0' && b <= '9')
    {
        x = b - '0';
        x += (a - '0') * 10;
    }
    else
    {
        x = a - '0';
    }
    return x;
}

string dfs (string str)
{
    // cout << "READ: " << str << endl;
    string ans;
    int len = str.length();
    for (int i = 0; i < len; i ++)
    {
        if (str[i] == '[')
        {
            int x = get_factor (str[i + 1], str[i + 2]), start, j = 0;
            if (x >= 10) start = i + 3;
            else start = i + 2;
            int taowa = 1;
            while (j < len && taowa)
            {
                if (str[start + j] == ']') taowa --;
                if (str[start + j] == '[') taowa ++;
                j ++;
            }
            j --;
            string subans = dfs (str.substr (start, j));
            for (int k = 0; k < x; k ++)
            {
                ans.append (subans);
            }
            i = start + j;
        }
        else if (str[i] != ']')
        {
            ans.append (1, str[i]);
        }
    }
    // cout << "WRITE: " << ans << endl;
    return ans;
}

int main ()
{
    string str;
    cin >> str;
    cout << dfs (str);
    return 0;
}