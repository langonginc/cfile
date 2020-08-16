/*
P1896  &&  P!*(^  ||  RP++

题目描述:
在N×N的棋盘里面放K个国王，使他们互不攻击，共有多少种摆放方案。国王能攻击到它上下左右，以及左上左下右上右下八个方向上附近的各一
个格子，共8个格子。

输入格式:
只有一行，包含两个数N，K （ 1 <=N <=9, 0 <= K <= N * N）

输出格式:
所得的方案数
*/
using namespace std;
const int N=15;
#include<iostream>
#include<cstdio>
#include<cstring>
int C(int a){
	int r=0;
	while(a!=0){
		r+=(a&1);
		a>>=1;
	}
	return r;
}
int n,k;
long long dp[N][2000][N*N],v[2000],vn,c[2000],ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<n);i++){
		if((i&(i<<1))==0){
			v[vn]=i,c[vn++]=C(i);
		}
	}
	for(int i=0;i<vn;i++){
		dp[1][i][c[i]]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<vn;j++){
			int jj=v[j];
			for(int x=0;x<vn;x++){
				int xx=v[x];
				if((xx&jj)==0 && ((xx>>1)&jj)==0 && (xx&(jj>>1))==0){
					for(int y=c[j];y<=k;y++){
						dp[i][j][y]+=dp[i-1][x][y-c[j]];
					}
				}
			}
		}
	}
	for(int i=0;i<vn;i++){
		ans+=dp[n][i][k];
	}
	cout<<ans<<endl;
	return 0;
}
