#include<iostream>
using namespace std;
#include<cstdio>
#include<stack>
#include<cstring>
const int debug = 0;
struct char_to_int {
	stack<int> tra;
	inline void creat_char(char a) {
		int make = a - '0';
		tra.push(make);
	}
	inline void creat_int(int a) {
		tra.push(a);
	}
	int carry_num() {
		int power = 1,ans = 0;
		while (!tra.empty()) {
			ans += tra.top() * power;
			power *= 10;
			tra.pop();
		}
		return ans;
	}
}cti;
const int inf = 1005;
int res;
int carry(char op, int ex1, int ex2) {
	int ans = 0;
	if (op == '-') {
		ans = ex1 - ex2;
		if (debug == 1)printf("%d - %d = %d", ex1, ex2, ans);
	}
	else if (op == '+') {
		ans = ex1 + ex2;
		if (debug == 1)printf("%d + %d = %d", ex1, ex2, ans);
	}
	else if (op == '*') {
		ans = ex1 * ex2;
		if (debug == 1)printf("%d * %d = %d", ex1, ex2, ans);
	}
	else if (op == '/') {
		ans = ex1 / ex2;
		if (debug == 1)printf("%d / %d = %d", ex1, ex2, ans);
	}
	return ans;
}
int main() {
	string s;
	cin >> s;
	int len = s.length();
	stack<int> c;
	bool times=true;
	for (int i = 0; i < len; i++) {
		if (s[i] == '@')break;
		if (s[i] >= '0' && s[i] <= '9') {
			int make = s[i] - '0';
			cti.creat_int(make);
		}
		else if (s[i] == '.') {
			c.push(cti.carry_num());
		}
		else {
			
			int ex1;
			int ex2;
			if (times == true) {
				ex2 = c.top();
				c.pop();
				times = false;
				ex1 = c.top();
				c.pop();
			}
			else {
				ex2 = c.top();
				c.pop();
				ex1 = res;
			}
			//printf("113");
			
			res = carry(s[i], ex1, ex2);
			if(debug==1)cout <<"ans is"<< res << endl;
		}
	}
	cout << res;
	return 0;
}
