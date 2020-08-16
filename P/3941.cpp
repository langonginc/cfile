#include<iostream>
using namespace std;
#include<cstdio>
typedef long long ll;
ll n,m,k,a[405][405],pre[405][405],mod[1000005],b[1000005];
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			b[0]=1;
			for(int l=1;l<=m;l++){
				mod[l]=(pre[j][l]-pre[i][l])%k;
				ans+=b[mod[l]];
				b[mod[l]]++;
			}
			for(int l=1;l<=m;l++){
				b[mod[l]]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
