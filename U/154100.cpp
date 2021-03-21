#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

int n;
map <string, int> mp;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int type;
        string str;
        cin >> type >> str;
        if (type == 1)
        {
            mp[str] ++;
        }
        if (type == 2)
        {
            cout << mp[str] << endl;
        }
    }
    return 0;
}
