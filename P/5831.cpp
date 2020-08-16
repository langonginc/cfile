#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M = 25;
int s[M][M],cow[M],ans,cc[M][M];
int main() {
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
            cc[i][s[i][j]]=j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c=0;
			for (int q = 1; q <= k; q++) {
				if(cc[q][i]>cc[q][j])
                {
                    c++;
                }
			}
			if (c==k) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
