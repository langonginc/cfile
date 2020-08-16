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
