#include<iostream>
#include<vector>
using namespace std;
vector<int>nw;
vector<int>nv;
void making(int w[],int v[],int x[],int n){
	int a=1;
	nw.push_back(0);
	nv.push_back(0);
	for(int i=1;i<=n;i++){
		a=1;
		while(a<x[i]+1){
			nw.push_back(w[i]*a);
			nv.push_back(v[i]*a);
			a=a*2;
		}
	}
}
int main(){
	//freopen("bag02.txt","r",stdin);
	int n,c;
	cin>>c>>n;
	int w[n+1],v[n+1],lenw[n+1];
	w[0]=0,v[0]=0,lenw[0]=0;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
		lenw[i]=c/w[i];
	}
	making(w,v,lenw,n);
	int times=nw.size()-1;//cout<<times<<endl;
	int f[c+1];
	for(int j=0;j<=c;j++){
		f[j]=0;
	}
	for(int i=1;i<=times;i++){
		for(int j=c;j>=nw[i];j--){
			f[j]=max(f[j],f[j-nw[i]]+nv[i]);
		}
	}
	cout<<f[c];
	return 0;
}
