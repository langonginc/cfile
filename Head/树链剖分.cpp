int size[ MAXN ] , fa[ MAXN ] , son[ MAXN ] , top[ MAXN ] , dep[ MAXN ] , l[ MAXN ] , r[ MAXN ] , v[ MAXN ];

#define cur linker[x][i]

//size表示子树大小
//dep表示深度
//son表示重儿子 
//top[x]表示x一直向上走，保证每次走的时候都是重儿子，能走到哪个点 

//第一遍DFS求出重儿子，深度，子树大小 
void dfs1( int x )
{
	size[x] = 1;
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] )
		{
			dep[ cur ] = dep[x] + 1 , fa[ cur ] = x;
			dfs1( cur ) , size[x] += size[ cur ];
			if( size[ cur ] > size[ son[x] ] ) son[x] = cur;
		}
}

int tot;

//求DFS序，当访问一个点的时候先DFS其重儿子，其他儿子顺序任意 
void dfs2( int x , int t )
{
	l[x] = ++tot , top[x] = t;
	if( son[x] ) dfs2( son[x] , t );
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] && cur != son[x] )
			dfs2( cur , cur );
	r[x] = tot;
}
