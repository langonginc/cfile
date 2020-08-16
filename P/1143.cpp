#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int now,aft;
	cin>>now;
	string a;
	cin>>a;
	int len=a.length(),ten,power;		
	cin>>aft;
	if(now!=10){
		if(now<10){
			power=1,ten=0;
			for(int i=len-1;i>=0;i--){
				ten=ten+(a[i]-'0')*power;
				power=power*now;
			}
		}
		else{
			
			power=1,ten=0;
			for(int i=len-1;i>=0;i--){
				if(a[i]>='0'&&a[i]<='9'){
					ten=ten+(a[i]-'0')*power;
				}
				else{
					ten=ten+(a[i]-'A'+10)*power;
				}
				//cout<<ten<<endl;
				power=power*now;
			}
		}
	}	
	else{
		power=1;ten=0;
		for(int i=len-1;i>=0;i--){
			ten=ten+(a[i]-'0')*power;
			power=power*10;
		}
	}
	//cout<<"zhuanwei10jinzhi :"<<ten<<endl;

	int yushu[40];
	if(aft==10)cout<<ten;
	else{
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
	}
	
	return 0;
}
