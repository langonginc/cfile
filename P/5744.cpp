#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class person{
public:
  string name;
  int age,s;


  int& operator[] (int num){
    if(num==2)return age;
    return s;
  }
  void up()
  {
    age++,s*=1.2;
    if(s>600)s=600;
  }
};
int main()
{
  person a[1000];
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i].name;
    for(int j=2;j<=3;j++)
      cin>>a[i][j];
    a[i].up();
    cout<<a[i].name<<" ";
    for(int j=2;j<=3;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}

