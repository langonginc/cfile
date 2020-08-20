#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5+5;

/*
Vars
nn 下一个点的位置
sum[u] 以u为根的子树的总结点个数
num[u] u节点出现的次数
son[u][0 OR 1] 点u的左儿子(0)右儿子(1)
val[u] u节点的值
fa[u] u节点的父亲
root 当前树根
*/

int n,fa[inf],son[inf][2],val[inf],sum[inf],num[inf],nn,root;

inline void pushUp (int p)
{
	sum[p] = sum[son[p][0]] + sum[son[p][1]] + num[p];
}

/*
获取点是左节点还是右节点
返回 (0 OR 1) 左/右
*/

inline int getWitch (int x)
{
	return (son[fa[x]][1] == x);
}

/*
旋转
顺序很重要,先连x和z,否则下面f[y]被改成x,get(y)会错
*/

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

/*
Splay 将x旋转到根
1 如果当前点和父节点还有父节点的父亲都在一条链上，先旋转父亲，在旋转自己
2 否则旋转2次自己
*/

inline void splay (int x)
{
	while (fa[x])
	{
		int y = fa[x], z = fa[y];
		if (z)
		{
			if (getWitch(x) == getWitch(y)) //1
			{
				rotate(y);
			}
			else //2
			{
				rotate(x);
			}
		}
		rotate(x); //1 OR 2
	}
	root = x;
}

/*
插入
1 找到合适的位置
2 如果已经存在点了，那么就计数器++
3 否则添加点、更新父亲
*/

inline void insert (int x)
{
    int cur = root, old = 0;
    while (cur && val[cur] != x) //1
    {
        old = cur;
        cur = son[cur][x > val[cur]];
    }
    if (cur != 0) //2
    {
        num[cur] ++,
        sum[cur] ++;
    }
    else //3
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

/*
Query1 获取排名
1.1 如果当前点值大于Query值，向左继续
1.2 如果当前点和Query值相等，输出ans+1
1.3 否则向右继续
*/

inline int getRank (int x)
{
    int cur = root, ans = 0;
    while (cur)
    {
        if (val[cur] > x) //1.1
        {
            cur = son[cur][0];
        }
        else
        {
            ans += sum[son[cur][0]];
            if (val[cur] == x) //1.2
            {
                splay(cur);
                return ans + 1;
            }
            ans += num[cur]; //1.3
            cur = son[cur][1];
        }
    }
    return 0;
}

/*
Query2 获取第x的值
2.1 如果当前点的左儿子的总结点数大于Query值，向左继续
2.2 如果当前点的左儿子的总结点数加上当前点的个数大于Query值，返回当前点的val
2.3 否则向右继续
*/

inline int getK (int x)
{
    int cur = root;
    while (true)
    {
        if (sum[son[cur][0]] >= x) //2.1
        {
            cur = son[cur][0];
        }
        else if (sum[son[cur][0]] + num[cur] >= x) //2.2
        {
            splay (cur);
            return val[cur];
        }
        else //2.3
        {
            x -= sum[son[cur][0]] + num[cur];
            cur = son[cur][1];
        }
    }
}

/*
Query3 找前驱
3.1 如果当前点的右孩子不是空点的话向右继续
3.2 否则返回当前点
*/

inline int getPre ()
{
    int cur = son[root][0];
    while (son[cur][1])
    {
        cur = son[cur][1];
    }
    return cur;
}

/*
Query4 找后继
4.1 如果当前点的左孩子不是空点的话就向左继续
4.2 否则返回当前点
*/

inline int getSuc ()
{
    int cur = son[root][1];
    while (son[cur][0])
    {
        cur = son[cur][0];
    }
    return cur;
}

/*
del删除
1 如果不存在，返回
2 如果根的num大于1，计数器--
3 如果根只有1个孩子就拿他来替补
4 否则{
	1 将del点的前驱splay为根
	2 让旧根成为根的右孩子
	3 左孩子为空
}
*/

inline void del (int x)
{
    if (getRank(x) == 0) //1
    {
        return;
    }
    if (num[root] > 1) //2
    {
        num[root] --;
        sum[root] --;
        return;
    }
    if (son[root][0] == 0) //3 => Left
    {
        root = son[root][1];
        fa[root] = 0;
        return;
    }
    if (son[root][1] == 0) //3 => Right
    {
        root = son[root][0];
        fa[root] = 0;
        return;
    }
    int newRoot = getPre();
    int oldRoot = root;
    splay(newRoot); //4.1
    son[root][1] = son[oldRoot][1]; //4.2
    fa[son[oldRoot][1]] = root; //4.3
    pushUp (root);
}

/*
Main 洛谷P3369
*/

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
