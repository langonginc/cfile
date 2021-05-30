#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;

class Task
{
    public:
        ll now, q, s;
        // priority_queue <int, vector<int>, greater<int> > q;
        bool operator< (const Task &a) const
        {
            if (now != a.now)
            {
                return now > a.now;
            }
            else return q > a.q;
        }
};

Task taskinit (ll now, ll q, ll s)
{
    Task task;
    task.now = now, task.q = q, task.s = s;
    return task;
}

priority_queue <Task> q;
ll n, k;

int main ()
{
    scanf ("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        char x[10];
        ll q1, t;
        scanf ("%s %lld%lld", x, &q1, &t);
        q.push (taskinit(t, q1, t));
    }
    while (k --)
    {
        Task task = q.top();
        q.pop();
        printf ("%lld\n", task.q);
        task.now += task.s;
        q.push(task);
    }
    return 0;
}