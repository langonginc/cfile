// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// bool ch[30];
// string str;
//
// int main ()
// {
//     cin >> str;
//     ll len = str.length();
//     ll ans = 0;
//     bool flag = true;
//     for (ll i = 0; i < len; i ++)
//     {
//         if (ch[str[i] - 'A'])
//         {
//             flag = false;
//             break;
//         }
//         ch[str[i] - 'A'] = true;
//     }
//     if (flag)
//     {
//         cout << "-1";
//         return 0;
//     }
//     for (ll i = 0; i < len; i ++)
//     {
//         ll l = 0;
//         memset (ch, 0, sizeof(ch));
//         for (ll j = i; j < len; j ++)
//         {
//             if (ch[str[i] - 'A'])
//             {
//                 l ++;
//                 ans = max(ans, l);
//                 break;
//             }
//             l ++;
//             ch[str[i] - 'A'] = true;
//         }
//     }
//     cout << ans;
//     return 0;
// }


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string str;
int last[30];

int main ()
{
    memset(last, -1, sizeof(last));
    cin >> str;
    int len = str.length();
    int ans = 0, nexti = 0;
    // for (int i = 0; i < len; i ++)
    // {
    //     nexti = i;
    //     int left = 0;
    //     if (left < i)
    //     // for (int left = i - 1; left >= 0; left --)
    //     {
    //         if (last[str[i] - 'A'] < left)
    //         {
    //             ans = max (ans, i - left + 1);
    //         }
    //         else
    //         {
    //             left = last[str[i] - 'A'];
    //             nexti = i - 1;
    //         }
    //         last[str[i] - 'A'] = i;
    //     }
    //     i = nexti;
    // }
    int i = 1, left = 0;
    nexti = i;
    while (i < len)
    {
        i = nexti;
        while (left >= i)
        {
            i ++;
        }
        nexti = i;
        if (i >= len) break;
        if (last[str[i] - 'A'] < left)
        {
            ans = max (ans, i - left + 1);
            printf ("[INFO] LEFT %d, RIGHT %d, ACCEPT, ANS %d\n", left, i, ans);
            nexti ++;
        }
        else
        {
            printf ("[INFO] LEFT %d, RIGHT %d, NOT DIFF, LAST %d\n", left, i, last[str[i] - 'A']);
            left = last[str[i] - 'A'] + 1;
        }
        last[str[i] - 'A'] = i;
    }
    if (ans == len + 1) cout << -1;
    else cout << ans;
    return 0;
}
