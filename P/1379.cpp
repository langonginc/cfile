#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
struct emd{
	int step;
	int p,x,y;
	string s;
	emd(int step,int p,int x,int y,string s):step(step),p(p),x(x),y(y),s(s){}
};
string now,end="123804765";
int cx[4]={0,0,-1,1};
int cy[4]={-1,1,0,0};

int main(){
	string start;
	cin>>start;
	queue<emd>q;
	set<string>r;
	r.insert(start);
	for(int i=0;i<9;i++){
		if(start[i]=='0'){
			q.push(emd(0,i,i/3,i%3,start));
		}
	}
	while(!q.empty()){
		emd d=q.front();
		q.pop();
		now=d.s;//d.sÏÖÔÚµÄ×´Ì¬ 
		int beforep=d.p;//d.pÏÖÔÚµÄÎ»ÖÃ 
		int beforex=d.x;
		int beforey=d.y;
		if(d.s==end){
			cout<<d.step<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){			
			int xx=beforex+cx[i];
			int yy=beforey+cy[i];
			int w=3 * xx + yy;
			if(xx>=0&&xx<3&&yy>=0&&yy<3){
				swap(now[beforep],now[w]);
				if(r.count(now)==0){
					q.push(emd(d.step+1,w,xx,yy,now));
					r.insert(now);
				}
				swap(now[beforep],now[w]);
			}
		}	
	}
	return 0;
}
