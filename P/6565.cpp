#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n, ans;
char str [200], name [50], ansname[50];

int count ()
{
  int tot = 0;
  for (int i = 1; i < strlen(str) - 1; i ++)
  {
    if (str [i] == 'o' && str [i - 1] == 's' && str [i + 1] == 's')
    {
      tot ++;
    }
  }
  return tot;
}

int main ()
{
  scanf ("%d\n", &n);
  for (int i = 1; i <= n; i ++)
  {
    cin >> name >> str;
    //scanf ("%s\n%s\n", name, str);
    int k = count();
    // printf ("I'm in case %d: name is '%s', str is '%s', %d\n", i, name, str, k);
    if (ans < k)
    {
      ans = k;
      strcpy (ansname, name);
    }
    if (ans == k && strcmp(ansname, name)!=0)
    {
      strcat (ansname, " ");
      strcat (ansname, name);
    }
  }
  cout << ansname << "\n" << ans << "\n";
  return 0;
}
