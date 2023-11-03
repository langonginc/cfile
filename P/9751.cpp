#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 5;

struct Member {
    ll v, a;
};

struct Edge {
    ll v, w;
    bool operator < (const Edge &x) const {
        return w > x.w;
    }
};

vector <Member> adj[maxn];
priority_queue <Edge> q;

ll n, m, k;
ll dis[maxn][105];
bool vis[maxn][105];

int main () {
    scanf ("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        ll u, v, a;
        scanf ("%lld%lld%lld", &u, &v, &a);
        adj[u].push_back({ v, a });
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0] = 0;
    q.push({1, 0});
    while (! q.empty()) {
        ll u = q.top().v;
        ll now = q.top().w;
        q.pop();
        if (vis[u][now % k]) continue;
        vis[u][now % k] = true;
        for (int i = 0; i < adj[u].size(); i ++) {
            ll v = adj[u][i].v;
            ll startTime = adj[u][i].a;
            ll thisTime;
            if (now >= startTime) {
                thisTime = now;
            } else {
                thisTime = ((startTime - now + k - 1) / k) * k + now;
            }
            ll nextK = (thisTime + 1) % k;
            if (dis[v][nextK] > thisTime + 1) {
                dis[v][nextK] = thisTime + 1;
                q.push({ v, thisTime + 1 });
            }
        }
    }
    if (vis[n][0]) printf ("%lld\n", dis[n][0]);
    else printf ("-1\n");
    return 0;
}