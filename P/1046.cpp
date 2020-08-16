#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct type{
	int size;
	vector<int> val,like;
}kind[65];
int f[65][32005],position[65];
int main(){
	int n,money,v,p,q,wh=0;
	cin>>money>>n;
	for(int i=1;i<=n;i++){
		cin>>v>>p>>q;
		if(q==0){
			wh++;
			kind[wh].size=0;
			kind[wh].val.push_back(v);
			kind[wh].like.push_back(p);
			position[i]=wh;
		}
		else if(q>=1){
			kind[position[q]].size++;
			kind[position[q]].val.push_back(v);
			kind[position[q]].like.push_back(p);
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<position[i]<<"P"<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=wh;i++){
//		cout<<i<<"<"<<kind[i].size<<" & ";
//		for(int j=0;j<=kind[i].size;j++){
//			cout<<kind[i].val[j]<<"^"<<kind[i].like[j]<<endl;
//		}
//		cout<<")"<<endl;
//	}
	int len=wh;
	for(int i=1;i<=len;i++){
		for(int j=10;j<=money;j+=10){
			if(kind[i].val[0]>j){
				f[i][j]=f[i-1][j];
//				cout<<"FULL"<<endl;
			}
			else{
				type now=kind[i];
				int c=max(f[i-1][j],f[i-1][j-now.val[0]]+now.like[0]*now.val[0]);
				if(now.size>0){ 
					if(now.val[1]+now.val[0]<=j){
						c=max(c,f[i-1][j-now.val[1]-now.val[0]]+now.val[1]*now.like[1]+now.val[0]*now.like[0]);
					}
				}
				if(now.size==2){
					if(now.val[2]+now.val[0]<=j){
						c=max(c,f[i-1][j-now.val[2]-now.val[0]]+now.val[2]*now.like[2]+now.val[0]*now.like[0]);
					}
					if(now.val[1]+now.val[2]+now.val[0]<=j){
						c=max(c,f[i-1][j-now.val[2]-now.val[1]-now.val[0]]+now.val[2]*now.like[2]+now.val[1]*now.like[1]+now.val[0]*now.like[0]);
					}
				}
				f[i][j]=c;
//				cout<<i<<" "<<j<<" "<<c<<endl;
			}
		}
	}
	cout<<f[len][money];
	return 0;
}
