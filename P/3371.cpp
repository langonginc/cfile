#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
const int INF = 2147483647;
const int inf = 100005;
struct node {
	int v, w;
};
node make(int v, int w) {
	node a;
	a.v = v;
	a.w = w;
	return a;
}
int n, m, s;
int d[inf], vis[inf];
vector<node>adj[inf];
void spfa() {
	queue<int> q;
	for (int i = 0; i <= n; i++) {
		d[i] = INF;
	}
	q.push(s);
	vis[s] = 1;
	d[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].v;
			int w = adj[u][i].w;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if (vis[v]==0) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main() 
{
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back(make(y, w));
	}
	spfa();
	for (int i = 1; i <= n; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
	return 0;
}
