#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 100005;

class People
{
    public:
        int score, ability, id;
        bool operator < (const People &tmp) const
        {
            if (score < tmp.score)
            {
                return true;
            }
            else if (score == tmp.score && id > tmp.id)
            {
                return true;
            }
            return false;
        }
};

int n, r, q, win[inf], lose[inf], wincount, losecount;
People people[inf], temp[inf];

int main ()
{
    scanf ("%d%d%d", &n, &r, &q);
    n <<= 1;
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &people[i].score);
        people[i].id = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &people[i].ability);
    }
    sort (people + 1, people + n + 1);
    for (int i = 1; i <= r; i ++)
    {
        wincount = 0, losecount = 0;
        for (int j = 1; j <= n; j += 2)
        {
            if (people[j].ability > people[j + 1].ability)
            {
                people[j].score ++;
                win[++ wincount] = people[j].id;
                lose[++ losecount] = people[j + 1].id;
            }
            else
            {
                people[j + 1].score ++;
                win[++ wincount] = people[j + 1].id;
                lose[++ losecount] = people[j].id;
            }
        }
        int winpoint = 1, losepoint = 1, idcount = 0;
        while (winpoint <= wincount && losepoint <= losepoint)
        {
            printf ("@");
            if (people[win[winpoint]] < people[lose[losepoint]])
            {
                temp[++ idcount] = people[lose[losepoint ++]];
            }
            else
            {
                temp[++ idcount] = people[win[winpoint ++]];
            }
        }
        while (winpoint <= wincount) temp[++ idcount] = people[win[winpoint ++]];
        while (losepoint <= losepoint) temp[++ idcount] = people[lose[losepoint ++]];
        memcpy (people, temp, sizeof(temp));
        printf ("?");
    }
    printf ("%d\n", people[q].id);
    return 0;
}