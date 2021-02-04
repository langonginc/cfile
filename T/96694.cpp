#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

int box[5][5];
bool vis[10];

bool f(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (
        box[x1][y1] + box[x2][y2] + box[x3][y3] == 15 &&
        box[x1][y1] > 0 && box[x1][y1] <= 9 &&
        box[x2][y2] > 0 && box[x2][y2] <= 9 &&
        box[x3][y3] > 0 && box[x3][y3] <= 9
    )
    {
        return true;
    }
    else return false;
}

int main ()
{
    for (int a = 1; a <= 9; a ++)
    {
        if(a!=5)
        {
            for (int b = 1; b <= 9; b ++)
            {
                memset (vis, 0, sizeof(vis));
                if(b!=5 && b!=a)
                {
                    box[1][1] = a, box[1][2] = b;
                    box[1][3] = 15 - a - b;
                    box[2][1] = 20 - 2*a - b;
                    box[2][2] = 5;
                    box[2][3] = 2*a + b - 10;
                    box[3][1] = a + b - 5;
                    box[3][2] = 10 - b;
                    box[3][3] = 10 - a;
                    bool flag = true;
                    for (int i = 1; i <= 3; i ++)
                    {
                        for (int j = 1; j <= 3; j ++)
                        {
                            if (vis[box[i][j]])
                            {
                                flag = false;
                            }
                            else
                            {
                                vis[box[i][j]] = true;
                            }
                        }
                    }
                    for (int i = 1; i <= 9; i ++)
                    {
                        if (!vis[i])
                        {
                            flag = false;
                        }
                    }
                    if (!flag)
                    {
                        continue;
                    }
                    if (
                        f(1,1,1,2,1,3) &&
                        f(2,1,2,2,2,3) &&
                        f(3,1,3,2,3,3) &&
                        f(1,1,2,1,3,1) &&
                        f(1,2,2,2,3,2) &&
                        f(1,3,2,3,3,3) &&
                        f(1,1,2,2,3,3) &&
                        f(1,3,2,2,3,1)
                    )
                    {
                        for (int i = 1; i <= 3; i ++)
                        {
                            for (int j = 1; j <= 3; j ++)
                            {
                                printf ("%d ", box[i][j]);
                            }
                            printf ("\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
