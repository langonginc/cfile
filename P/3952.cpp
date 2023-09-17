#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 105;

class Function {
    public:
    int var, len;
    bool run;
    Function () {}
    Function (int v, int l, bool r) {
        var = v, len = l, run = r;
    }
};

int n, o, err, calc, ans;
stack <Function> s;
bool hasVar[30];

void init () {
    memset (hasVar, 0, sizeof (hasVar));
    hasVar['n' - 'a'] = true;
    while (!s.empty ()) {
        s.pop ();
    }
    err = false;
    calc = 0;
    ans = 0;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t --) {
        init ();
        scanf ("%d ", &n);
        char temp[maxn];
        scanf ("%s", temp);
        if (temp[2] == '1') {
            o = 0;
        } else {
            if (temp[5] == ')') {
                o = temp[4] - '0';
            } else {
                o = (temp[4] - '0') * 10 + (temp[5] - '0');
            }
        }
        for (int i = 1; i <= n; i ++) {
            char type[maxn], var[maxn], start[maxn], end[maxn];
            int varNum, startNum, endNum;
            scanf ("%s", type);
            if (type[0] == 'F') {
                scanf ("%s%s%s", var, start, end);
                varNum = var[0] - 'a';
                if (hasVar[varNum]) {
                    err = true;
                } else {
                    hasVar[varNum] = true;
                }
                if (err) continue;
                if (start[0] == 'n') {
                    startNum = 1e5;
                } else {
                    startNum = strlen (start) == 1 ? start[0] - '0' : (start[0] - '0') * 10 + (start[1] - '0');
                }
                if (end[0] == 'n') {
                    endNum = 1e5;
                } else {
                    endNum = strlen (end) == 1 ? end[0] - '0' : (end[0] - '0') * 10 + (end[1] - '0');
                }
                bool run;
                if (endNum - startNum >= 0 && s.empty()) {
                    run = true;
                } else if (endNum - startNum >= 0 && !s.empty() && s.top().run) {
                    run = true;
                } else {
                    run = false;
                }
                s.push (Function (varNum, endNum - startNum, run));
                if (run && endNum - startNum > 1e4) {
                    calc ++;
                    ans = max (ans, calc);
                }
            } else if (type[0] == 'E') {
                if (s.empty ()) {
                    err = true;
                }
                if (err) continue;
                Function top = s.top ();
                s.pop ();
                hasVar[top.var] = false;
                if (top.run && top.len > 1e4) {
                    calc --;
                }
            }
        }
        if (!s.empty ()) {
            err = true;
        }
        if (err) {
            printf ("ERR\n");
        } else {
            printf (o == ans ? "Yes\n" : "No\n");
        }
    }
    return 0;
}