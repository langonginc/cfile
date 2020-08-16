#include<iostream>
#include<cstring>
using namespace std;
int f[40][25000];
int main(){
	memset(f,0,sizeof(f));
	int c,n,mx;
	cin>>c>>n;
	int w[n];
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			mx=0;
			if(w[i]>j){
				f[i][j]=f[i-1][j];
				//cout<<"FULL"<<endl;
			}
			else{
				//for(int k=0;k<=j/w[i];k++){
				//	mx=max(mx,f[i-1][j-w[i]*k]+k*w[i]);
				//}
				f[i][j]=max(f[i-1][j-w[i]]+w[i],f[i-1][j]);
				//cout<<"PUT  "<<g<<"  TIMES"<<endl;
			}
			
		}
	}
	int a=c-f[n][c];
	cout<<a;
	return 0;
}
