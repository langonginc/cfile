#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string multiply(string a, string b) {
    a = reverse(a);
    b = reverse(b);
    int len = a.size() + b.size();
    string res(len, '0');
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int x = (a[i] - '0') * (b[j] - '0');
            int y = res[i + j] - '0' + x;
            res[i + j] = y % 10 + '0';
            res[i + j + 1] += y / 10;
        }
    }
    while (len > 1 && res[len - 1] == '0') len--;
    res = res.substr(0, len);
    res = reverse(res);
    return res;
}

string add(string a, string b) {
    a = reverse(a);
    b = reverse(b);
    int len = max(a.size(), b.size()) + 1;
    string res(len, '0');
    for (int i = 0; i < len - 1; i++) {
        int x = (i < a.size() ? a[i] - '0' : 0);
        int y = (i < b.size() ? b[i] - '0' : 0);
        int z = res[i] - '0' + x + y;
        res[i] = z % 10 + '0';
        res[i + 1] += z / 10;
    }
    while (len > 1 && res[len - 1] == '0') len--;
    res = res.substr(0, len);
    res = reverse(res);
    return res;
}

string premul [55], preadd[55];

int main() {
    int n;
    cin >> n;
    premul[1] = "1";
    preadd[1] = "1";
    string tmp = "1";
    for (int i = 2; i <= n; i ++)
    {
        tmp = add (tmp, "1");
        premul[i] = multiply (premul[i - 1], tmp);
        preadd[i] = add (preadd[i - 1], premul[i]);
    }
    cout << preadd[n];
    return 0;
}