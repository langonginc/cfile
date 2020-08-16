namespace Noder{
  typedef long long ll;
  class node{
    public:
    ll x, y, step, life;
    bool operator< ( const node &a ) const
    {
      return a.step<step;
    }
    bool operator> ( const node &a ) const
    {
      return a.step>step;
    }
  };
  inline node init( ll x, ll y, ll step, ll life )
  {
    node a;
    a.x = x, a.y = y, a.step = step, a.life = life;
    return a;
  }
  class pairs{
    public:
    ll x, y;
  };
  inline pairs input( ll x, ll y )
  {
    pairs a;
    a.x = x, a.y = y;
    return a;
  }
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
using Noder::node;
using Noder::init;
using Noder::pairs;
using Noder::input;
typedef long long ll;
#define INF 2147483646
const short dx[4] = { 0, 0, 1, -1 };
const short dy[4] = { 1, -1, 0, 0 };
ll n, m, mp[15][15], vis[15][15][10], ans;
queue <node> q;
node start;
pairs End;

int main()
{
  ans = INF;
  scanf( "%lld%lld", &n, &m );
  for( int i = 1; i <= n; i++ )
  {
    for( int j = 1; j <= m; j++ )
    {
      scanf( "%lld", &mp[i][j] );
      if( mp[i][j] == 2 )
      {
        start = init( i, j, 0, 6 );
      }
      if( mp[i][j] == 3 )
      {
        End = input( i, j );
      }
    }
  }
  q.push( start );
  vis[start.x][start.y][start.life] = start.step;

  while( !q.empty() )
  {
    node now = q.front();
    q.pop();
    if( now.life == 0 )
    {
      continue;
    }
    if( mp[now.x][now.y] == 3 )
    {
      ans = now.step;
      break;
    }

    if( mp[now.x][now.y] == 4 )
    {
      now.life = 6;
    }
    for( int i = 0; i < 4; i++ )
    {
      int xx = now.x + dx[i],
          yy = now.y + dy[i];
      if( xx <= 0 || xx > n || yy <= 0 || yy > m )
      {
        continue;
      }
      if( mp[xx][yy] == 0 )
      {
        continue;
      }
      else
      {
        if( vis[xx][yy][now.life - 1] )
        {
          continue;
        }
        vis[xx][yy][now.life - 1] = 1;
        q.push( init( xx, yy , now.step + 1, now.life - 1 ) );
      }
    }
  }

  printf( "%lld", ans >= INF ? -1 : ans );
  return 0;
}
