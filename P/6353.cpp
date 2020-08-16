#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int now,aft;
	now=2;
	string a;
	cin>>a;
	int len=a.length(),ten,power;
	aft=8;
	if(now<10){
		power=1,ten=0;
		for(int i=len-1;i>=0;i--){
			ten=ten+(a[i]-'0')*power;
			power=power*now;
		}
	}
	//cout<<"zhuanwei10jinzhi :"<<ten<<endl;
	int yushu[999940];
		int w=0;
		while(ten>=0){
			yushu[w]=ten%aft;
			ten=ten/aft;
			w++;
			if(ten==0)break;
		}
		char p;
		for(int i=w-1;i>=0;i--){
			if(yushu[i]>10){
				p='A'+yushu[i]%10;
				cout<<p;
			}
			else{
				cout<<yushu[i];
			}
		}

	return 0;
}
