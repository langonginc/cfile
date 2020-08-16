#include <iostream>
#include <cstdio>
using namespace std;
const int mxn = 50005;

class node
{
  public:
    int len, num, l, r, tag;
} tree [mxn * 4];

inline int lc (int p)
{
  return p << 1;
}

inline int rc (int p)
{
  return p << 1 | 1;
}

void movetag (int p, int l, int r, int tag)
{
  if (tag == 1)
  {
    tree [p].num = tree [p].l = tree [p].r = 0;
    tree [p].tag = 1;
  }
  else
  {
    tree [p].num = tree [p].l = tree [p].r = r - l + 1;
    tree [p].tag = 2;
  }
}

void pushup (int p)
{
  if (tree [lc (p)].num == tree [lc (p)].len)
    tree [p].l = tree [lc (p)].num + tree [rc (p)].l;
  else
    tree [p].l = tree [lc (p)].l;
  if (tree [rc (p)].num == tree [rc (p)].len)
    tree [p].r = tree [rc (p)].num + tree [lc (p)].r;
  else
    tree [p].r = tree [rc (p)].r;
  tree [p].num = tree [lc (p)].r + tree [rc (p)].l;
  tree [p].num = max (tree [p].num, tree [lc (p)].num);
  tree [p].num = max (tree [p].num, tree [rc (p)].num);
}

void pushdn (int p, int l, int r)
{
  if (tree [p].tag == 0)
    return;
  int mid = (l + r) >> 1;
  movetag (lc (p), l, mid, tree [p].tag);
  movetag (rc (p), mid + 1, r, tree [p].tag);
  tree [p].tag == 0;
}

void build (int p, int l, int r)
{
  tree [p].len = r - l + 1;
  if (l == r)
  {
    tree [p].num = tree [p].l = tree [p].r = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build (lc (p), l, mid);
  build (rc (p), mid + 1, r);
  pushup (p);
  return;
}

int query (int p, int l, int r, int k)
{
  if (l == r)
    return l;
  int mid = (l + r) >> 1;
  pushdn (p, l, r);
  if (tree [lc (p)].num >= k)
    return query (lc (p), l, mid, k);
  if (tree [lc (p)].r + tree [rc (p)].l >= k)
    return mid + 1 - tree [lc (p)].r;
  if (tree [rc (p)].num >= k)
    return query (rc (p), mid + 1, r, k);
  return 0;
}

void checkin (int p, int l, int r, int ql, int qr)
{
  if (ql <= l && r <= qr)
  {
    tree [p].num = tree [p].l = tree [p].r = 0;
    tree [p].tag = 1;
    return;
  }
  pushdn(p, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid)
    checkin (lc (p), l, mid, ql, qr);
  if (mid < qr)
    checkin (lc (p), mid + 1, r, ql, qr);
  pushup (p);
}

void checkout (int p, int l, int r, int ql, int qr)
{
  if (ql <= l && r <= qr)
  {
    tree [p].num = tree [p].l = tree [p].r = r - l + 1;
    tree [p].tag = 2;
    return;
  }
  pushdn(p, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid)
    checkout (lc (p), l, mid, ql, qr);
  if (mid < qr)
    checkout (lc (p), mid + 1, r, ql, qr);
  pushup (p);
}

int main ()
{
  scanf ("%d%d", &n, &m);
  build (1, 1, n);
  for (int i = 1; i <= m; i ++)
  {
    int opt, x, y;
    scanf ("%d", &opt);
    if (op == 1)
    {
      scanf ("&d", &x);
      int pos = query (1, 1, n, x);
      printf ("%d\n", pos);
      if (pos != 0)
        checkin (1, 1, n, pos, pos + x - 1);
    }
    else{
      scanf ("%d%d", &x, &y);
      checkout (1, 1, n, x, x + y - 1);
    }
  }
  return 0;
}

