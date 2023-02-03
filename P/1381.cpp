#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
using namespace std;
const int inf = 1005;
const int mnf = 1e5 + 5;

map <string, int> r;
string name[inf];

int n, m, a[mnf], b[inf], c[inf], sum, maxsum, ans = INT_MAX;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> name[i];
        r[name[i]] = i;
    }
    cin >> m;
    string tmp;
    for (int i = 1; i <= m; i ++)
    {
        cin >> tmp;
        if (r.find (tmp) != r.end ())
        {
            a[i] = r[tmp];
            if (c[a[i]] ++ == 0)
            {
                maxsum ++;
            }
        }
        else
        {
            a[i] = 0;
        }
    }
    cout << maxsum << endl;
    if (maxsum == 0){
        cout << 0 << endl;          // #7 WA
        return 0;
    }

    int left = 0, right = 0;
    while (left <= right && right <= m)
    {
        if (sum == maxsum)
        {
            ans = min (ans, right - left + 1);
            if (b[a[left]] == 1 && a[left] != 0)
            {
                sum --;
            }
            b[a[left]] --;
            left ++;
        }
        else
        {
            right ++;
            if (b[a[right]] == 0 && a[right] != 0)
            {
                sum ++;
            }
            b[a[right]] ++;
        }
    }
    cout << ans << endl;
    return 0;
}