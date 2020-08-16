#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ans[n];
	bool a[n];
	for(int i=0;i<n;i++){
		a[i]=true;
		ans[i]=0;
	}
	int j=0,pointer=0,number_off=0,k=0;
	while(j<n){
		if(pointer>=n)pointer=0;
		if(a[pointer]){
			number_off++;
		}
		if(number_off==m){
			ans[k++]=pointer+1;
			a[pointer]=false;
			number_off=0;
			j++;
		}
		pointer++;
	}
	for(int i=0;i<k;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
