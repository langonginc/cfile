#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
const int inf=100005;
struct ticket{
	int time,used,price;
	inline void add(int time_,int price_){
		price=price_,time=time_,used=0;
	}
	inline int get_time(){
		return time;
	}
	inline int get_price(){
		return price;
	}
	inline int get_used(){
		return used;
	}
	inline void put_used(int used_){
		used=used_;
	}
}q[inf];
//ticket add(int time,int price){
//	ticket a;
//	a.price=price,a.time=time,a.used=0;
//	return a;
//}
int n,head,tail,cost;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int type,time,price;
		scanf("%d%d%d",&type,&price,&time);
		if(type==0){
			cost+=price;
			q[tail++].add(time+45,price);
		}
		else{
			while(head<tail&&q[head].get_time()<time){
				head++;
			}
			bool find=false;
			for(int j=head;j<tail;j++){
				if(q[j].get_price()>=price&&q[j].get_used()==0){
					q[j].put_used(1);
					find=true;
					break;
				}
			}
			if(!find){
				cost+=price;
			}
		}
	}
	printf("%d\n",cost);
	return 0;
}
