#include<iostream>
using namespace std;
int main(){
    unsigned int a,b;
    cin>>a;
    b=(a<<16)+(a>>16);
    cout<<b;
    return 0;
}
