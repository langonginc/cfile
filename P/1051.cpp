#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 10005;

class Student
{
    public:
    string name;
    bool office, west;
    int s1, s2, s3, sum, pos;
    Student () {}
    Student (int _pos, string _name, int _s1, int _s2, bool _office, bool _west, int _s3)
    {
        pos = _pos, name = _name, s1 = _s1, s2 = _s2, office = _office, west = _west, s3 = _s3;
        domoney ();
    }
    int domoney ()
    {
        sum = 0;
        if (s1 > 80 && s3 >= 1)
        {
            sum += 8000;
        }
        if (s1 > 85 && s2 > 80)
        {
            sum += 4000;
        }
        if (s1 > 90)
        {
            sum += 2000;
        }
        if (s1 > 85 && west)
        {
            sum += 1000;
        }
        if (s2 > 80 && office)
        {
            sum += 850;
        }
        return sum;
    }
    bool operator < (const Student &x) const
    {
        if (sum > x.sum) return true;
        if (sum < x.sum) return false;
        if (pos < x.pos) return true;
        return false;
    }
} a[inf];

int n, sum;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        string str;
        int s1, s2, s3;
        char c1, c2;
        cin >> str >> s1 >> s2 >> c1 >> c2 >> s3;
        a[i] = Student (i, str, s1, s2, (c1 == 'N' ? 0 : 1), (c2 == 'N' ? 0 : 1), s3);
    }
    sort (a + 1, a + n + 1);
    cout << a[1].name << endl << a[1].sum << endl;
    for (int i = 1; i <= n; i ++)
    {
        sum += a[i].sum;
    }
    cout << sum << endl;
    return 0;
}