#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#define MAXN 300010

using namespace std;

int n , m , cnt[ MAXN << 2 ] , ans[ MAXN ] , size[ MAXN ] , fa[ MAXN ] , dep[ MAXN ] , son[ MAXN ] , top[ MAXN ] , tot;
int L[ MAXN ] , R[ MAXN ] , s[ MAXN ] , t[ MAXN ] , l[ MAXN ] , w[ MAXN ];
vector < int > linker[ MAXN ] , v[ MAXN ];

inline int read()
{
	register int x = 0 , ch = getchar();
	while( !isdigit( ch ) ) ch = getchar();
	while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
	return x;
}

inline void addedge( int x , int y )
{
	linker[x].push_back( y );
	linker[y].push_back( x );
}

#define cur linker[x][i]

void dfs1( int x )
{
	size[x] = 1;
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] )
		{
			fa[ cur ] = x , dep[ cur ] = dep[x] + 1;
			dfs1( cur ) , size[x] += size[ cur ];
			if( size[ cur ] > size[ son[x] ] ) son[x] = cur;
		}
}

void dfs2( int x , int t )
{
	L[x] = ++tot , top[x] = t;
	if( son[x] ) dfs2( son[x] , t );
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] && cur != son[x] )
			dfs2( cur , cur );
	R[x] = tot;
}

inline int lca( int x , int y )
{
	while( top[x] != top[y] )
	{
		if( dep[ top[x] ] < dep[ top[y] ] ) swap( x , y );
		x = fa[ top[x] ];
	}
	return dep[x] < dep[y] ? x : y;
}

struct ask
{
	int num , v;
	ask( int x , int y ) : num( x ) , v( y ) {}
};

vector < ask > q[ MAXN ];

int main()
{
	n = read() , m = read();
	for( register int i = 1 ; i < n ; i++ ) addedge( read() , read() );
	for( register int i = 1 ; i <= n ; i++ ) w[i] = read();
	dfs1( 1 ) , dfs2( 1 , 1 );
	for( register int i = 1 ; i <= m ; i++ ) s[i] = read() , t[i] = read() , l[i] = lca( s[i] , t[i] );
	for( register int i = 1 ; i <= m ; i++ ) v[ L[ s[i] ] ].push_back( dep[ s[i] ] + MAXN ) , v[ L[ fa[ l[i] ] ] ].push_back( -( dep[ s[i] ] + MAXN ) );
	for( register int i = 1 ; i <= n ; i++ )
		if( w[i] <= MAXN )
			q[ R[i] ].push_back( ask( i , 1 ) ) , q[ L[i] - 1 ].push_back( ask( i , -1 ) );
	for( int x = 1 ; x <= n ; x++ )
	{
		for( register int i = 0 ; i < v[x].size() ; i++ )
			if( v[x][i] > 0 ) cnt[ v[x][i] ]++;
			else cnt[ -v[x][i] ]--;
		for( register int i = 0 ; i < q[x].size() ; i++ )
			ans[ q[x][i].num ] += q[x][i].v * cnt[ dep[ q[x][i].num ] + w[ q[x][i].num ] + MAXN ];
	}
	memset( cnt , 0 , sizeof( cnt ) );
	for( register int i = 0 ; i <= n ; i++ ) v[i].clear();
	for( register int i = 1 ; i <= m ; i++ ) v[ L[ t[i] ] ].push_back( -dep[ s[i] ] + 2 * dep[ l[i] ] + MAXN ) , v[ L[ l[i] ] ].push_back( -( -dep[ s[i] ] + 2 * dep[ l[i] ] + MAXN ) );
	for( int x = 1 ; x <= n ; x++ )
	{
		for( register int i = 0 ; i < v[x].size() ; i++ )
			if( v[x][i] > 0 ) cnt[ v[x][i] ]++;
			else cnt[ -v[x][i] ]--;
		for( register int i = 0 ; i < q[x].size() ; i++ )
			ans[ q[x][i].num ] += q[x][i].v * cnt[ dep[ q[x][i].num ] - w[ q[x][i].num ] + MAXN ];
	}
	for( register int i = 1 ; i <= n ; i++ ) printf( "%d" , ans[i] ) , putchar( i == n ? '\n' : ' ' );
	return 0;
}
