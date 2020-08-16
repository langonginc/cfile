#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (q.size() >= 2) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}