// // #include <iostream>
// // #include <cstdio>
// // #include <cstring>
// // using namespace std;
// // typedef long long ll;
// // bool ch[30];
// // string str;
// //
// // int main ()
// // {
// //     cin >> str;
// //     ll len = str.length();
// //     ll ans = 0;
// //     bool flag = true;
// //     for (ll i = 0; i < len; i ++)
// //     {
// //         if (ch[str[i] - 'A'])
// //         {
// //             flag = false;
// //             break;
// //         }
// //         ch[str[i] - 'A'] = true;
// //     }
// //     if (flag)
// //     {
// //         cout << "-1";
// //         return 0;
// //     }
// //     for (ll i = 0; i < len; i ++)
// //     {
// //         ll l = 0;
// //         memset (ch, 0, sizeof(ch));
// //         for (ll j = i; j < len; j ++)
// //         {
// //             if (ch[str[i] - 'A'])
// //             {
// //                 l ++;
// //                 ans = max(ans, l);
// //                 break;
// //             }
// //             l ++;
// //             ch[str[i] - 'A'] = true;
// //         }
// //     }
// //     cout << ans;
// //     return 0;
// // }
//
//
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
//
// string str;
// int last[30];
//
// int main ()
// {
//     memset(last, -1, sizeof(last));
//     cin >> str;
//     int len = str.length();
//     int ans = 0, nexti = 0;
//     // for (int i = 0; i < len; i ++)
//     // {
//     //     nexti = i;
//     //     int left = 0;
//     //     if (left < i)
//     //     // for (int left = i - 1; left >= 0; left --)
//     //     {
//     //         if (last[str[i] - 'A'] < left)
//     //         {
//     //             ans = max (ans, i - left + 1);
//     //         }
//     //         else
//     //         {
//     //             left = last[str[i] - 'A'];
//     //             nexti = i - 1;
//     //         }
//     //         last[str[i] - 'A'] = i;
//     //     }
//     //     i = nexti;
//     // }
//     int i = 1, left = 0;
//     nexti = i;
//     while (i < len)
//     {
//         i = nexti;
//         while (left >= i)
//         {
//             i ++;
//         }
//         nexti = i;
//         if (i >= len) break;
//         if (last[str[i] - 'A'] < left)
//         {
//             ans = max (ans, i - left + 1);
//             printf ("[INFO] LEFT %d, RIGHT %d, ACCEPT, ANS %d\n", left, i, ans);
//             nexti ++;
//         }
//         else
//         {
//             printf ("[INFO] LEFT %d, RIGHT %d, NOT DIFF, LAST %d\n", left, i, last[str[i] - 'A']);
//             left = last[str[i] - 'A'] + 1;
//         }
//         last[str[i] - 'A'] = i;
//     }
//     if (ans == len + 1) cout << -1;
//     else cout << ans;
//     return 0;
// }


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string str;
bool vis[28];

int main ()
{
    cin >> str;
    int len = str.length(), ans = 0;
    for (int i = 0; i < 26 && i < len; i ++)
    {
        // memset (vis, 0, sizeof (vis));
        // for (int j = 0; j < i; j ++)
        // {
        //     if (vis[str[j] - 'A'])
        //     {
        //         printf ("[INFO] FAILED ON sort AT 1 time, ch=%c, index=%d, long=%d\n", str[j], j, i);
        //         cout << ans + 1 << endl;
        //         return 0;
        //     }
        //     vis[str[j] - 'A'] = true;
        // }
        for (int s = 0; s + i < len; s ++)
        {
            memset (vis, 0, sizeof (vis));
            for (int j = s; j <= i + s; j ++)
            {
                if (vis[str[j] - 'A'])
                {
                    // printf ("[INFO] FAILED ON sort AT 1 time, ch=%c, index=%d, long=%d\n", str[j], j, i);
                    cout << ans + 1 << endl;
                    return 0;
                }
                vis[str[j] - 'A'] = true;
            }
            // if (vis[str[s + i] - 'A'])
            // {
            //     printf ("[INFO] FAILED ON sort AT 2 time, ch=%c, index=%d, long=%d\n", str[s+i], s+i, i);
            //     cout << ans + 1 << endl;
            //     return 0;
            // }
            // vis[str[s + i] - 'A'] = true;
            // vis[str[s] - 'A'] = false;
            // ans = i;
        }
        ans = i;
    }
    cout << ((ans + 1 == len) ? -1 : ans) << endl;
    return 0;
}
