#include<iostream>
using namespace std;
const int de = 0;
int a[10005], b[10005] ,f[10005];
inline int max(int x, int y) {
	return x > y ? x : y;
}
inline int min(int x, int y) {
	return x < y ? x : y;
}
int main() {
	int v, n, c, r=0;
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		r += a[i];
	}
	if (r < v) {
		cout << "Impossible";
		if (de==1)cout << "0";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = c; j >= b[i]; j--) {
			f[j] = max(f[j], f[j - b[i]] + a[i]);
		}
	}
	for (int i = 0; i <= v; i++) {
		if (f[i] >= v) {
			cout << c - i;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}
