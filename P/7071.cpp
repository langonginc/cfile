#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll n;

int main (){
	// freopen ("power.in", "r", stdin);
	// freopen ("power.out", "w", stdout);
	cin >> n;
	if (n < 2){
		cout << "-1";
		return 0;
	}
	if (n % 2 == 1){
		cout << "-1";
		return 0;
	}
	ll pow;
	pow = 1;
	while (n%pow < n){
		pow *= 2;
	}
	pow /= 2;
	while (n >= 1){
    if(n >= pow)
		  cout << pow << " ";
		n %= pow;
		pow /= 2;
	}
	return 0;
}
