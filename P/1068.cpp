#include <iostream>
#include <algorithm>
using namespace std;

class Corp{
  public:
  int a, b;
  bool operator < (const Corp &x) const
  {
    if (b == x.b)
      return a < x.a;
    return b > x.b;
  }
};

int n, m;
Corp a[5005];

int main ()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i ++){
    cin >> a[i].a >> a[i].b;
  }
  sort (a + 1, a + n + 1);
  int k = m * 1.5;
  int g = k;
  while (a[g + 1].b == a[k].b) g ++;
  cout << a[k].b << " " << g << endl;
  for (int i = 1; i <= g; i ++)
  {
    cout << a[i].a << " " << a[i].b << endl;
  }
  return 0;
}
