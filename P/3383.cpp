#include<iostream>
#include<cstdio>
using namespace std;
typedef long long l;
l n,g[10000005],G=0;
bool c[10000005];
void p(void){
	for(int i=2;i<=n;i++){
		if(c[i]==false){
			g[G++]=i;
		}
		for(int j=0;j<G&&g[j]*i<=n;j++){
			c[g[j]*i]=true;
			if(i%g[j]==0){
				break;
			}
		}
	}
	return;
}
int main(){
	for(int i=0;i<=n;i++)c[i]=false;
	int m,d; 
	cin>>n>>m;
	p(); 
//	for(int i=2;i<=n;i++){
//		cout<<i<<"="<<c[i]<<"      ";
//	}
	for(int i=0;i<m;i++){
		cin>>d;
		if(d==1){
			cout<<"No"<<endl;
			continue;
		}
		if(c[d]==true){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
