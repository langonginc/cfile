#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n, a[35];
map <int, int> mp;
map <int, int> mp2;
int main ()
{
    // freopen ("OUTPUT.txt", "w", stdout);
    mp[1] = 0;
    mp[2] = 1;
    mp[4] = 2;
    mp[8] = 3;
    mp[16] = 4;
    mp[32] = 5;
    mp[64] = 6;
    mp[128] = 7;
    mp[256] = 8;
    mp[512] = 9;
    mp[1024] = 10;
    mp[2048] = 11;
    mp[4096] = 12;
    mp[8192] = 13;
    mp[16384] = 14;
    mp[32768] = 15;
    mp[65536] = 16;
    mp[131072] = 17;
    mp[262144] = 18;
    mp[524288] = 19;
    mp[1048576] = 20;
    mp[2097152] = 21;
    mp[4194304] = 22;
    mp[8388608] = 23;
    mp[16777216] = 24;
    mp[33554432] = 25;
    mp[67108864] = 26;
    mp[134217728] = 27;
    mp[268435456] = 28;
    mp[536870912] = 29;
    mp[1073741824] = 30;
    mp2[0] = 1;
    mp2[1] = 2;
    mp2[2] = 4;
    mp2[3] = 8;
    mp2[4] = 16;
    mp2[5] = 32;
    mp2[6] = 64;
    mp2[7] = 128;
    mp2[8] = 256;
    mp2[9] = 512;
    mp2[10] = 1024;
    mp2[11] = 2048;
    mp2[12] = 4096;
    mp2[13] = 8192;
    mp2[14] = 16384;
    mp2[15] = 32768;
    mp2[16] = 65536;
    mp2[17] = 131072;
    mp2[18] = 262144;
    mp2[19] = 524288;
    mp2[20] = 1048576;
    mp2[21] = 2097152;
    mp2[22] = 4194304;
    mp2[23] = 8388608;
    mp2[24] = 16777216;
    mp2[25] = 33554432;
    mp2[26] = 67108864;
    mp2[27] = 134217728;
    mp2[28] = 268435456;
    mp2[29] = 536870912;
    mp2[30] = 1073741824;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int x, y;
        scanf ("%d", &x);
        if (x == 1)
        {
            scanf ("%d", &y);
            a[mp[y]] ++;
        }
        if (x == 2)
        {
            int ans = 0;
            for (int j = 0; j <= 30; j ++)
            {
                if (a[j] > 0)
                {
                    ans += mp2[j];
                    a[j] --;
                }
            }
            printf ("%d\n", ans);
        }
    }
    return 0;
}