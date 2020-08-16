#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
using namespace std;
const int INF=0x3f3f3f3f;
string n;
int m,len;
int adj[20][20],r[100],trans[10];
void multiplication(int c){
	for(int i=0;i<100;i++){
		r[i]*=c;
	}
	for(int i=0;i<99;i++){
		if(r[i]>9){
			r[i+1]+=r[i]/10;
			r[i]=r[i]%10;
		}
	}
}
int main(){
	r[0]=1;
	cin>>n;
	int a,b;
	scanf("%d",&m);
	len=n.length();
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		adj[a][b]=1;
	}
	for(int i=0;i<=9;i++){
		adj[i][i]=1;
	}
	for(int k=0;k<=9;k++){
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
				adj[i][j]=adj[i][j]||(adj[i][k]&&adj[k][j]);
			}
		}
	}
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			cout<<adj[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        	if(adj[i][j])trans[i]++;
		}
    }
    for(int i=0;i<n.length();i++){
    	int d=n[i]-'0';
    	multiplication(trans[d]);
	}
//	for(int i=0;i<100;i++)cout<<r[i]<<" ";
	int z=99;
	while(r[z--]==0);
	for(int i=z+1;i>=0;i--){
		printf("%d",r[i]);
	}
	return 0;
}
