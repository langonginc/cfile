#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5 + 5;
int t, n, ans;
string s;

int main ()
{
    cin >> t;
    while (t --)
    {
        cin >> n >> s;
        ans = INT_MAX;
        for (int i = 0; i <= 26; i ++)
        {
            int l = 0, r = n - 1, num = 0;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    l ++, r --;
                }
                else
                {
                    if (s[l] == i + 'a')
                    {
                        num ++, l ++;
                    }
                    else if (s[r] == i + 'a')
                    {
                        num ++, r --;
                    }
                    else
                    {
                        num = INT_MAX;
                        break;
                    }
                }
            }
            ans = min (ans, num);
        }
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}