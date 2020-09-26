#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int inf = 3005;
const int INF = 0x4fffff;

int n, m, s1, s2, t1, t2, ans = INF;
int vis[inf], dis1[inf], dis2[inf], dis3[inf];
vector <int> edge[inf];

void Spfa1 (int x)
{
    queue<int> q;
	memset(vis , 0 , sizeof(vis));
	q.push(x);
	dis1[x] = 0;
	vis[x] = 1;
	while(!q.empty()){
		int xx = q.front();
		q.pop();
		vis[xx] = 0;
		for(int i = 0; i < edge[xx].size(); i++){
			int y = edge[xx][i];
			if(dis1[y] > dis1[xx] + 1){
				dis1[y] = dis1[xx] + 1;
				if(!vis[y]){
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

void Spfa2 (int x)
{
    queue<int> q;
	memset(vis , 0 , sizeof(vis));
	q.push(x);
	dis2[x] = 0;
	vis[x] = 1;
	while(!q.empty()){
		int xx = q.front();
		q.pop();
		vis[xx] = 0;
		for(int i = 0; i < edge[xx].size(); i++){
			int y = edge[xx][i];
			if(dis2[y] > dis2[xx] + 1){
				dis2[y] = dis2[xx] + 1;
				if(!vis[y]){
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

void Spfa3 (int x)
{
    queue<int> q;
	memset(vis , 0 , sizeof(vis));
	q.push(x);
	dis3[x] = 0;
	vis[x] = 1;
	while(!q.empty()){
		int xx = q.front();
		q.pop();
		vis[xx] = 0;
		for(int i = 0; i < edge[xx].size(); i++){
			int y = edge[xx][i];
			if(dis3[y] > dis3[xx] + 1){
				dis3[y] = dis3[xx] + 1;
				if(!vis[y]){
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
    {
		int x , y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cin >> s1 >> t1 >> s2 >> t2;
	for(int i = 1; i <= n; i++) 
        dis1[i] = dis2[i] = dis3[i] = INF;
	Spfa1(1);
	Spfa2(s1);
	Spfa3(s2);
	if(dis1[s1] > t1 || dis1[s2] > t2){ 
		cout << -1;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		ans = min(ans , dis1[i] + dis2[i] + dis3[i]);
	cout << m - ans; 
	return 0;
}
