#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
bool b=false;
int n,k=1;
int main(){
    scanf("%d",&n);
    cin >> s;
    while (!b){
        k++;
        for ( int i = 0 ; i <= n - k ; i++ ){
            string ss;
            ss=s.substr(i,k);
            if (s.find(ss,i+1)!=string::npos ){
                break;
            }
            if (i==n-k){
                cout << k << endl;
                b = true;
                break;
            }
        }
    }
    return 0;
}