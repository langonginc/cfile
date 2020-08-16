#include<iostream>
using namespace std;
int n,ans_,c[11];
int ans[10000][11];
void hanke(int times,int g){
	if(times>10){
		if(g==0){
			for(int i=1;i<=10;i++){
				ans[ans_][i]=c[i];
			}
			ans_++;
		}
		return;
	}
	for(int i=1;i<=3&&i<=g;i++){
		c[times]=i;
		hanke(times+1,g-i);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<10000;i++){
		for(int j=0;j<11;j++){
			ans[i][j]=0;
		}
	}
	for(int i=0;i<11;i++){
		c[i]=0;
	}
	ans_=0;
	hanke(1,n);
	cout<<ans_<<endl;
	for(int i=0;i<ans_;i++){
		for(int j=1;j<=10;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
