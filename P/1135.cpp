#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,start,finsh,card[205];
double result=0x9f;
bool used[205];
void d(int floor,double step){
	int downfloor,upfloor;
	if(floor==finsh){
		result=min(result,step);
		return;
	}
	else if(step>result){
		return;
	}
	else{
		downfloor=floor-card[floor];
		upfloor=floor+card[floor];
		if(!used[downfloor]&&downfloor>0){
			used[downfloor]=true;
			d(downfloor,step+1);
			used[downfloor]=false;
		}
		if(!used[upfloor]&&upfloor<=n){
			used[upfloor]=true;
			d(upfloor,step+1);
			used[upfloor]=false;
		}
	}
}
int main(){
	cin>>n>>start>>finsh;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	d(start,0);
	if(result==0x9f){
		cout<<"-1";
	}
	else{
		cout<<result; 
	}
	return 0;
}
