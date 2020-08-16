#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  char a[5005];
  cin>>a;
  sort(a,a+strlen(a));
  cout<<a;
  return 0;
}

// ! WA
