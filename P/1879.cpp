/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int RP=2147483646;
typedef long long ll;
const int N=15;
int m,n,fid[N],vc,sta,t;
ll v[N],dp[N][1<<13],ans;
int main(){
	RP++;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		sta=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			sta=(sta<<1)+t;
		}
		fid[i]=sta;
	}
	for(int i=0;i<(1<<n);i++){
		if((i&(i>>1))==0){
			v[vc++]=i;
		}
	}
	for(int i=0;i<vc;i++){
		sta=v[i];
		if((sta&fid[1])==sta){
			dp[1][i]=1;
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=0;j<vc;j++){
			int jj=v[j];
			if((jj&fid[i])==jj){
				for(int k=0;k<vc;k++){
					int kk=v[k];
					if((jj&kk)==0){
						dp[i][j]=(dp[i][j]+dp[i-1][k])%100000000;
					}
				}
			}
				
		}
	}
	for(int i=0;i<vc;i++){
		ans=(ans+dp[m][i])%100000000;
	}
	printf("%lld\n",ans);
	return 0;
}
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int maxP = 13;
const int moder = 1e8;

int n, m, a[maxP], validState[1 << maxP], validCount, dp[maxP][1 << maxP];

int main()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			int x;
			scanf ("%d", &x);
			if (x)
			{
				a[i] |= (1 << j);
			}
		}
	}
	for (int s = 0; s < (1 << maxP); s ++)
	{
		if (s & (s >> 1)) continue;
		validState[++ validCount] = s;
	}

	// process line 1
	for (int i = 1; i <= validCount; i ++)
	{
		int s = validState[i];
		if ((s & a[1]) == s)
		{
			dp[1][s] = 1;
		}
	}
	// process other
	for (int i = 2; i <= n; i ++)
	{
		for (int j = 1; j <= validCount; j ++)
		{
			int s = validState[j];
			if ((s & a[i]) != s) continue;
			for (int k = 1; k <= validCount; k ++)
			{
				int pre = validState[k];
				if (dp[i - 1][pre] && (s & pre) == 0)
				{
					dp[i][s] = (dp[i][s] + dp[i - 1][pre]) % moder;
				}
			}
		}
	}
	// calc ans
	int ans = 0;
	for (int i = 1; i <= validCount; i ++)
	{
		ans = (ans + dp[n][validState[i]]) % moder;
	}
	printf ("%d\n", ans);
	return 0;
}