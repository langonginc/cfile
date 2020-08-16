#include <iostream>
#include <stack>
using namespace std;
int main() {
    int sum = 0;
    stack<int> s;
    int t;
    while (cin >> t) {
        if (t == 0)break;
        s.push(t);
        sum += s.size() * t;
    }
    cout << sum << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();    
    }    
    cout << endl;    
    return 0;
}
