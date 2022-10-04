// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// #include<cmath>
// #include<queue>
// #include<cstdlib>
// using namespace std;
// typedef long long ll;
// struct type{
// 	int x,y;
// 	type(int x,int y):x(x),y(y){}
// };
// const int M=2147483647;
// queue<type>q;
// int n,m,t[105][105],du[105][105],f[105][105],maxL=-M;
// const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
// void find(){
// 	while(!q.empty()){
// 		int x=q.front().x,y=q.front().y;
// 		q.pop();
// 		for(int i=0;i<4;i++){
// 			int nx=x+dx[i],ny=y+dy[i];
// 			if(x<0||y<0||x>n-1||y>m-1){
// 				continue;
// 			}
// 			if(t[x][y]>t[nx][ny]){
// 				du[nx][ny]--;
// 				if(f[x][y]>=f[nx][ny]){
// 					f[nx][ny]=f[x][y]+1;
// 				}
// 				maxL=max(maxL,f[x][y]);
// 				if(du[nx][ny]==0){
// 					q.push(type(nx,ny));
// 					//du[nx][ny]=-M;
// 				}
// 			}
// 		}
// 	}
// 	return ;
// }
// int main(){
// 	scanf("%d%d",&n,&m);
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			scanf("%d",&t[i][j]);
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			for(int k=0;k<4;k++){
// 				int x=i+dx[k],y=j+dy[k];
// 				if(x<0||y<0||x-1>n||y-1>m){
// 					continue;
// 				}
// 				else if(t[x][y]>t[i][j]){
// 					du[i][j]++;
// 				}
// 			}
// 		}
// 	}
// 	memset(f,~0x3f,sizeof(f));
// //	memset(f,~0x7ffffff,sizeof(f));
// //	memset(f,,sizeof(f));
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(du[i][j]==0){
// 				q.push(type(i,j));
// 				f[i][j]=0; 
// 				//du[i][j]=-M;
// 			}
// 		}
// 	}
// 	find();
// 	cout<<maxL+1;
// 	return 0;
// }

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 105;
const int dx[5] = {0, 0, 0, 1, -1};
const int dy[5] = {0, 1, -1, 0, 0};

class Pos
{
    public:

    int x, y;
    Pos (){}
    Pos (int _x, int _y) { x = _x, y = _y; }
};

queue <Pos> q;
int n, m, a[inf][inf], deg[inf][inf], dp[inf][inf], ans = 1;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            scanf ("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            for (int k = 1; k <= 4; k ++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                if (a[i][j] < a[nx][ny])
                {
                    deg[i][j] ++;
                }
            }
        }
    }
    memset (dp, ~0x3f, sizeof (dp));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (deg[i][j] == 0)
            {
                dp[i][j] = 1;
                q.push (Pos (i, j));
            }
        }
    }
    while (!q.empty ())
    {
        int x = q.front ().x, y = q.front ().y;
        q.pop ();
        for (int i = 1; i <= 4; i ++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if (a[x][y] > a[nx][ny])
            {
                deg[nx][ny] --;
                dp[nx][ny] = max (dp[nx][ny], dp[x][y] + 1);
                ans = max (ans, dp[nx][ny]);
                if (deg[nx][ny] == 0)
                {
                    q.push (Pos (nx, ny));
                }
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}