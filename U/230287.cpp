#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main ()
{
    int n, ans = 0;
    string str;
    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i ++)
    {
        getline (cin, str);
        for (int j = 0; j < str.length(); j ++)
        {
            if (str[j] == ' ') continue;
            if (str[j] == '#')
            {
                if (str[j + 1] == ' ') 
                {
                    bool flag = false;
                    for (int k = j + 1; k < str.length(); k ++)
                    {
                        if (str[k] != ' ')
                        {
                            flag = true;
                        }
                    }
                    if (flag)
                    {
                        ans ++;
                    }
                }
                break;
            }
            break;
        }
    }
    printf ("%d\n", ans);
    return 0;
}