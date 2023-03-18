/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

const int inf = 1e9 + 5;
const int mxn = 1e5 + 5;

class node
{
  public:
    int count, del, lc, rc;
} tree [mxn * 50];

int nn = 1;
int q = 0;

inline void movetag (int p)
{
  tree[p].del = 1,
  tree[p].count = 0;
}

inline void pushup (int p)
{
  tree [p].count = tree [tree [p].lc].count + tree [tree [p].rc].count;
}

inline void pushdn (int p)
{
  if (tree [p].del == 1)
  {
    tree [p].del = 0;
    movetag (tree [p].lc);
    movetag (tree [p].rc);
  }
}

void insert (int p, int l, int r, int q)
{
  if (l == r)
  {
    tree [p].del = 0;
    tree [p].count ++;
    return;
  }
  else
  {
    pushdn (p);
    int mid = (l + r) >> 1;
    if (q <= mid)
    {
      if (tree [p].lc == 0)
        tree [p].lc = ++ nn;
      insert (tree [p].lc, l, mid, q);
    }
    else
    {
      if (tree [p].rc == 0)
        tree [p].rc = ++ nn;
      insert (tree [p].rc, mid + 1, r, q);
    }
    pushup (p);
  }
}

void remove (int p, int l, int r, int ql, int qr)
{
  if (p == 0 || tree [p].del == 1 || tree [p].count == 0)
    return;
  if (ql <= l && r <= qr)
  {
    tree [p].del = 1,
    tree [p].count = 0;
    return;
  }
  int mid = (l + r) >> 1;
  pushdn (p);
  if (ql <= mid)
    remove (tree [p].lc, l, mid, ql, qr);
  if (mid < qr)
    remove (tree [p].rc, mid + 1, r, ql, qr);
  pushup (p);
}

int querys (int p, int l, int r, int ql, int qr)
{
  if (p == 0 || tree [p].del == 1 || tree [p].count == 0)
    return 0;
  if (ql <= l && r <= qr)
    return tree [p].count;
  pushdn (p);
  int ans = 0,
      mid = (l + r) >> 1;
  if (ql <= mid)
    ans += querys (tree [p].lc, l, mid, ql, qr);
  if (mid < qr)
    ans += querys (tree [p].rc, mid + 1, r, ql, qr);
  return ans;
}

int queryk (int p, int l, int r, int ql, int qr, int k)
{
  if (p == 0 || tree [p].del == 1 || tree [p].count == 0)
    return -1;
  if (l == r)
  {
    if (tree [p].count >= k)
      return l;
    else
      return -1;
  }
  pushdn (p);
  int mid = (l + r) >> 1,
      count = 0,
      lc = tree [p].lc,
      rc = tree [p].rc;
  if (mid < qr)
  {
    count = querys (rc, mid + 1, r, ql, qr);
    if (count >= k)
      return queryk (rc, mid + 1, r, ql, qr, k);
  }
  if (ql <= mid)
  {
    return queryk (lc, l, mid, ql, qr, k - count);
  }
  return -1;
}

int main ()
{
  scanf ("%d", &q);
  for (int i = 1; i <= q; i ++)
  {
    //printf (" >> Case %d : Input is ", i);
    int opt, x, l, r, k;
    scanf ("%d", &opt);
    //printf ("\n >> Case %d : Result is ", i);
    switch (opt)
    {
      case 1:
        scanf ("%d", &x);
        insert (1, 1, inf, x);
        break;
      case 2:
        scanf ("%d%d", &l, &r);
        remove (1, 1, inf, l, r);
        break;
      case 3:
        scanf ("%d%d%d", &l, &r, &k);
        printf ("%d\n", queryk (1, 1, inf, l, r, k));
        break;
    }
  }
  return 0;
}

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e9 + 5;
const int mxn = 1e5 + 5;

class Tree
{
	public:
		int lc, rc, del, sum;
} tree[mxn * 30];

int n, m, cnt;

inline int & lc (int p)
{
	return tree[p].lc;
}

inline int & rc (int p)
{
	return tree[p].rc;
}

inline void pushUp (int p)
{
	tree[p].sum = tree[lc (p)].sum + tree[rc (p)].sum;
}

inline void moveTag (int p)
{
	tree[p].del = true;
	tree[p].sum = 0;
}

inline void pushDown (int p)
{
	if (tree[p].del)
	{
		tree[p].del = false;
		moveTag (lc (p));
		moveTag (rc (p));
	}
}

inline void insert (int* p, int l, int r, int val)
{
	if (*p == 0)
	{
		*p = ++ cnt;
	}
	if (l == r)
	{
		tree[*p].del = false;
		tree[*p].sum ++;
		return;
	}
	pushDown (*p);
	int mid = (l + r) >> 1;
	if (val <= mid)
	{
		insert (&lc (*p), l, mid, val);
	}
	else
	{
		insert (&rc (*p), mid + 1, r, val);
	}
	pushUp (*p);
}

void remove (int p, int l, int r, int ql, int qr)
{
	if (p == 0 || tree[p].del || tree[p].sum == 0)
	{
		return;
	}
	if (ql <= l && r <= qr)
	{
		tree[p].sum = 0;
		tree[p].del = true;
		return;
	}
	pushDown (p);
	int mid = (l + r) >> 1;
	if (ql <= mid)
	{
		remove (lc (p), l, mid, ql, qr);
	}
	if (mid < qr)
	{
		remove (rc (p), mid + 1, r, ql, qr);
	}
	pushUp (p);
}

int querySum (int p, int l, int r, int ql, int qr)
{
	if (p == 0 || tree[p].del || tree[p].sum == 0)
	{
		return 0;
	}
	if (ql <= l && r <= qr)
	{
		return tree[p].sum;
	}
	pushDown (p);
	int mid = (l + r) >> 1, ans = 0;
	if (ql <= mid)
	{
		ans += querySum (lc (p), l, mid, ql, qr);
	}
	if (mid < qr)
	{
		ans += querySum (rc (p), mid + 1, r, ql, qr);
	}
	return ans;
}

int queryRank (int p, int l, int r, int k)
{
	if (l == r)
	{
        return l;
	}
	pushDown (p);
	int mid = (l + r) >> 1, count = 0;
	if (tree[rc (p)].sum >= k)
	{
        return queryRank (rc (p), mid + 1, r, k);
	}
	else
	{
		return queryRank (lc (p), l, mid, k - tree[rc (p)].sum);
	}
	return -1;
}

int root;

int main () {
	int q;
	scanf ("%d", &q);
	while (q --)
	{
		int op, l, r, k;
		scanf ("%d", &op);
		if (op == 1)
		{
			scanf ("%d", &k);
			insert (&root, 1, 1e9, k);
		}
		if (op == 2)
		{
			scanf ("%d%d", &l, &r);
			remove (root, 1, 1e9, l, r);
		}
		if (op == 3)
		{
			scanf ("%d%d%d", &l, &r, &k);
            int sum = querySum (root, 1, 1e9, l, r);
            if (sum < k) printf ("-1\n");
            else
            {
                sum = querySum (root, 1, 1e9, r + 1, 1e9);
			    printf ("%d\n", queryRank (root, 1, 1e9, k + sum));
            }
		}
	}
	return 0;
}