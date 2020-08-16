#include<iostream>
#include<cstdio>
#include<vector> 
#include<cstring>
using namespace std;
int c,n,w[10005],v[10005],f[100005],pointer;

int main(){
	scanf("%d%d",&c,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&v[i]);
	}
	vector<int> nw;
	vector<int> nv;
	nw.push_back(0);
	nv.push_back(0);
	for(int i=1;i<=n;i++){
		pointer=1;
		while(w[i]*pointer<=c){
			nw.push_back(w[i]*pointer);
			nv.push_back(v[i]*pointer);
			pointer*=2;
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=nw.size()-1;i++){
		for(int j=c;j>=nw[i];j--){
			f[j]=max(f[j],f[j-nw[i]]+nv[i]);
		}
	}
	cout<<f[c];
	return 0;
}
