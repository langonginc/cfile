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

