#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cstdlib>
using namespace std;
stack <int> k;
string s;
void print() {
	if (k.empty())cout << 0;
	bool qian = false;
	while (!k.empty()) {
		if (k.top() == 0) {
			if (qian == true) {
				printf("%d", k.top());
			}
		}
		else {
			printf("%d", k.top());
			if (qian == false)qian = true;
		}
		k.pop();
	}
}
int main() {
	cin >> s;
	int len = s.length();
	int i = 0;
	while (i<len) {
		bool q=false;
		while (i<=len) {
			if (i == len) {
				print();
				exit(0);
			}
			if (s[i] >= '0' && s[i] <= '9') {
				if (s[i] == '0') {
					if (q == true) {
						k.push(s[i] - '0');
					}
				}
				else {
					k.push(s[i] - '0');
					if (q == false) {
						q = true;
					}
				}
			}
			else {
				if (i >= len - 1&& s[len-1]!='%') {
					print();
					exit(0);
				}
				else {
					break;
				}
			}
			i++;
		}
		print();
		printf("%c", s[i]);
		i++;
	}
	return 0;
}
