#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

const int inf = 100005;
const int sINF = INT_MAX;

int sum[inf], num[inf], son[inf][2], val[inf], pri[inf], nn;

/*
sum[u] 以u为根的子树的总结点个数
num[u] u节点出现的次数
son[u][0 OR 1] 点u的左儿子(0)右儿子(1)
val[u] u节点的值
pri[u] u节点的优先级（随机数）
*/

inline void pushUp (int p)
{
  sum[p] = sum[son[p][0]] + sum[son[p][1]] + num[p];
}

/*
旋转
d=(0 OR 1) {
  0)左旋转
  1)右旋转
}
*/

inline void rotate (int &p, int d)
{
  int k = son[p][d ^ 1];
  son[p][d ^ 1] = son[k][d];
  son[k][d] = p;
  pushUp(p);
  pushUp(k);
  p = k;
}

/*
插入
1. 如果是空节点，创建
2. 如果是跟节点，计数器++
3. 否则{
  3.1. 插入到对应的孩子
  3.2. 如果不能满足Heap堆性质，旋转
}
*/

void insert (int &p, int x)
{
  if (p == 0) //1
  {
    p = ++nn;
    sum[p] = num[p] = 1;
    val[p] = x;
    pri[p] = rand();
    return;
  }
  else if (val[p] == x) //2
  {
    sum[p] ++,
    num[p] ++;
    return;
  }
  else //3
  {
    int k = (x > val[p]);
    insert (son[p][k], x); //3.1
    if (pri[son[p][k]] > pri[p]) //3.2
    {
      rotate (p, k ^ 1);
    }
    pushUp(p);
  }
}

/*
删除
1. 如果不存在，返回
2. 如果要删除的元素在子树里面，到对应的子树删除
3. 删除当前点{
  3.1. 当前点是叶子，直接删除
  3.2. 当前点在链上（只有1个孩子），用孩子替换
  3.3. 当前点有2个孩子，旋转后删除
}
*/

void del (int &p, int x)
{
  if (p == 0) //1
  {
    return;
  }
  else if (x < val[p]) //2 => 在左子树中
  {
    del(son[p][0], x);
  }
  else if (x > val[p]) //2 => 在右子树中
  {
    del(son[p][1], x);
  }
  else //3
  {
    if (num[p] > 1) //?
    {
      sum[p] --,
      num[p] --;
      return;
    }
    if (son[p][0] == 0 && son[p][1] == 0) //3.1
    {
      p = 0;
    }
    else if (son[p][0] != 0 && son[p][1] == 0) //3.2 => 有唯一左孩子
    {
      p = son[p][0];
    }
    else if (son[p][0] == 0 && son[p][1] != 0) //3.2 => 有唯一右孩子
    {
      p = son[p][1];
    }
    else // 3.3
    {
      int d = (pri[son[p][0]] > pri[son[p][1]]);
      rotate(p, d);
      del(son[p][d], x);
    }
  }
  pushUp(p);
}

/*
Query1 getRank
1.1. 如果不存在，返回0
1.2. 如果查询当前点，返回左子树的sum+1
1.3. 否则递归左右子树
*/

int getRank (int p, int x)
{
  if (p == 0) //1.1
  {
    return 0;
  }
  else if (val[p] == x) //1.2
  {
    return sum[son[p][0]] + 1;
  }
  else if (x < val[p]) //1.3 => 左
  {
    return getRank(son[p][0], x);
  }
  else //1.3 => 右
  {
    return sum[son[p][0]] + num[p] + getRank(son[p][1], x);
  }
}

/*
Query2 getNum
2.1. 如果左孩子的大小sum大于等于查询的排名rank，继续查询左子树
2.2. 如果左孩子的大小sum加上当前点的数量num小于查询排名rank，继续查询左子树减去当前点数量num
2.3. 否则返回当前点的val值（查询当前点）
*/

int getNum (int p, int x)
{
  if (sum[son[p][0]] >= x) //2.1
  {
    return getNum(son[p][0], x);
  }
  else if (sum[son[p][0]] + num[p] < x) //2.2
  {
    return getNum(son[p][1], x - sum[son[p][0]] - num[p]);
  }
  else //2.3
  {
    return val[p];
  }
}

/*
Query3 getPre 前驱
3.1. 找不到，返回INT_MIN
3.2. query值比当前值大或一样，查找左孩子
3.3. query值比当前值小，返回查询之后的右孩子的值和当前值的最大值
*/

int getPre (int p, int x)
{
  if (p == 0) //3.1
  {
    return -sINF;
  }
  else if (val[p] >= x) //3.2
  {
    return getPre(son[p][0], x);
  }
  else //3.3
  {
    return max (val[p], getPre(son[p][1], x));
  }
}

/*
Query4 getSuc 后继
4.1. 如果找不到，返回最大值
4.2. 当前值小于等于Query值，继续Query右面
4.3. 返回查询之后的左孩子的值和当前值的最小值
*/

int getSuc (int p, int x)
{
  if (p == 0) //4.1.
  {
    return sINF;
  }
  else if (val[p] <= x) //4.2
  {
    return getSuc(son[p][1], x);
  }
  else //4.3
  {
    return min (val[p], getSuc(son[p][0], x));
  }
}

/*
Main 洛谷P3369
*/

int main ()
{
  srand(time(NULL));
  int n, root = 0, opt, x;
  scanf ("%d", &n);
  while (n --)
  {
    scanf ("%d%d", &opt, &x);
    switch (opt) {
      case 1:
        insert(root, x);
        break;
      case 2:
        del (root, x);
        break;
      case 3:
        printf ("%d\n", getRank(root, x));
        break;
      case 4:
        printf ("%d\n", getNum(root, x));
        break;
      case 5:
        printf ("%d\n", getPre(root, x));
        break;
      case 6:
        printf ("%d\n", getSuc(root, x));
        break;
    }
  }
  return 0;
}
