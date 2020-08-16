#include<iostream>
using namespace std;
const int cost=19;
int main() {
	int a, b;
	cin >> a >> b;
	int money = 10 * a + b;
	cout << money / cost;
	return 0;
}
