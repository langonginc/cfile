#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N = 105;
const int M = 12;
int n, m, validcount;
ll field[N], dp[N][65][65], valid[ 1<<M ], count[ 1<<M ], ans;
int count1( int a) {
	int r=0;
	while (a != 0) {
		r += (a & 1);
		a >>= 1;
	}
	return r;
}
int main() {
	cin >> n >> m;	
	for (int i = 1; i <= n; i++) {
		char s; int status = 0;
		for (int j = 1; j <= m; j++) {
			cin >> s;
			if (s == 'H') {
				status = (status << 1) + 1;
			}
			else {
				status = (status << 1) + 0;
			}
			
		}
		field[i] = status;
	}
	for (int i = 0; i < (1 << m); i++) {
		if ((i & (i << 1)) == 0 && (i&(i<<2)) == 0 ) {
			valid[validcount] = i;
			count[validcount] = count1(i);
			validcount++;
		}
	}
	for (int i = 0; i < validcount; i++) {
		if ((valid[i] & field[1]) == 0) {
			dp[1][i][0] = count[i];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < validcount; j++) {
			ll jj = valid[j];
			if (jj & field[i])
				continue;
			for (int x = 0; x < validcount; x++) {
				ll xx = valid[x];
				if ((jj & xx) || (xx & field[i - 1]))
					continue;
				for (int y = 0; y < validcount; y++) {
					ll yy = valid[y];
					if ((jj & yy) || (xx & yy) || (yy & field[i - 2]))
						continue;
					dp[i][j][x] = max(dp[i][j][x], dp[i - 1][x][y] + count[j]);
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < validcount; ++i) {
		for (int j = 0; j < validcount; ++j) {
			ans = max(dp[n][i][j], ans);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
LanGongINC && LanGongDEV保留权利
*/
