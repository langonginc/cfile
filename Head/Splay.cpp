#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5+5;

int n,fa[inf],son[inf][2],val[inf],sum[inf],num[inf],nn,root;

inline void pushUp (int p)
{
	sum[p] = sum[son[p][0]] + sum[son[p][1]] + num[p];
}

inline int getWitch (int x)
{
	return (son[fa[x]][1] == x);
}

inline void rotate (int x)
{
	int y = fa[x],z = fa[y];
	int d = getWitch(x),w = son[x][d^1];
	son[y][d] = w,
	fa[w] = y,
	fa[x] = z;
	if (z != 0)
	{
		son[z][getWitch(y)] = x;
	}
	son[x][d^1] = y;
	fa[y] = x;
	pushUp(y),pushUp(x);
}

inline void splay (int x)
{
	while (fa[x])
	{
		int y = fa[x], z = fa[y];
		if (z)
		{
			if (getWitch(x) == getWitch(y))
			{
				rotate(y);
			}
			else
			{
				rotate(x);
			}
		}
		rotate(x);
	}
	root = x;
}

inline void insert (int x)
{
    int cur = root, old = 0;
    while (cur && val[cur] != x)
    {
        old = cur;
        cur = son[cur][x > val[cur]];
    }
    if (cur != 0)
    {
        num[cur] ++,
        sum[cur] ++;
    }
    else
    {
        cur = ++nn;
        if (old)
        {
            son[old][x > val[old]] = cur;
        }
        val[cur] = x;
        num[cur] = sum[cur] = 1;
        fa[cur] = old;
    }
    splay(cur);
}

inline int getRank (int x)
{
    int cur = root, ans = 0;
    while (cur)
    {
        if (val[cur] > x)
        {
            cur = son[cur][0];
        }
        else
        {
            ans += sum[son[cur][0]];
            if (val[cur] == x)
            {
                splay(cur);
                return ans + 1;
            }
            ans += num[cur];
            cur = son[cur][1];
        }
    }
    return 0;
}

inline int getK (int x)
{
    int cur = root;
    while (true)
    {
        if (sum[son[cur][0]] >= x)
        {
            cur = son[cur][0];
        }
        else if (sum[son[cur][0]] + num[cur] >= x)
        {
            splay (cur);
            return val[cur];
        }
        else
        {
            x -= sum[son[cur][0]] + num[cur];
            cur = son[cur][1];
        }
    }
}

inline int getPre ()
{
    int cur = son[root][0];
    while (son[cur][1])
    {
        cur = son[cur][1];
    }
    return cur;
}

inline int getSuc ()
{
    int cur = son[root][1];
    while (son[cur][0])
    {
        cur = son[cur][0];
    }
    return cur;
}

inline void del (int x)
{
    if (getRank(x) == 0)
    {
        return;
    }
    if (num[root] > 1)
    {
        num[root] --;
        sum[root] --;
        return;
    }
    if (son[root][0] == 0)
    {
        root = son[root][1];
        fa[root] = 0;
        return;
    }
    if (son[root][1] == 0)
    {
        root = son[root][0];
        fa[root] = 0;
        return;
    }
    int newRoot = getPre();
    int oldRoot = root;
    splay(newRoot);
    son[root][1] = son[oldRoot][1];
    fa[son[oldRoot][1]] = root;
    pushUp (root);
}

int main ()
{
  int opt, x;
  scanf ("%d", &n);
  while (n --)
  {
    scanf ("%d%d", &opt, &x);
    switch (opt) {
      case 1:
        insert(x);
        break;
      case 2:
        del (x);
        break;
      case 3:
        printf ("%d\n", getRank(x));
        break;
      case 4:
        printf ("%d\n", getK(x));
        break;
      case 5:
        insert(x);
        printf ("%d\n", val[getPre()]);
        del(x);
        break;
      case 6:
        insert(x);
        printf ("%d\n", val[getSuc()]);
        del(x);
        break;
    }
  }
  return 0;
}
