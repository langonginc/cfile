#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
  double m,h,bmi;
  cin>>m>>h;
  bmi=m/(h*h);
  if(bmi<18.5)
  {
    printf("Underweight\n");
  }
  else if(bmi<24)
  {
    printf("Normal\n");
  }
  else{
    cout<<bmi<<endl<<"Overweight"<<endl;
  }
  return 0;
}

