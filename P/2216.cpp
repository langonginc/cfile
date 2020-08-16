#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
//namespace queue{
//	#ifndef std
//	using namespace std;
//	#endif
//	#ifndef ll
//	typedef long long ll;
//	#endif
//	class queue_int{
//		int q[1000];
//		int head,tail,lon;
//		public:
//			inline int front(){
//				return q[head];
//			}
//			inline int back(){
//				return q[tail-1];
//			}
//			inline void push(const int in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//	class queue_char{
//		char q[1000];
//		int head,tail,lon;
//		public:
//			inline char front(){
//				return q[head];
//			}
//			inline char back(){
//				return q[tail-1];
//			}
//			inline void push(const char in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_double{
//		double q[1000];
//		int head,tail,lon;
//		public:
//			inline double front(){
//				return q[head];
//			}
//			inline double back(){
//				return q[tail-1];
//			}
//			inline void push(const double in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_two_int{
//		struct n{
//			int x,y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(int _x,int _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_two_char{
//		struct n{
//			char x,y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(char _x,char _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_two_intchar{
//		struct n{
//			int x;
//			char y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(int _x,char _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_two_doublechar{
//		struct n{
//			double x;
//			char y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(double _x,char _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};	
//	class queue_two_intdouble{
//		struct n{
//			int x;
//			double y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(int _x,double _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//	class queue_two_double{
//		struct n{
//			double x;
//			double y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(double _x,double _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//	class queue_two_ll{
//		struct n{
//			ll x;
//			ll y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(ll _x,ll _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//	class queue_two_intll{
//		struct n{
//			int x;
//			ll y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(int _x,ll _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//	class queue_two_doublell{
//		struct n{
//			double x;
//			ll y;
//		};
//		n q[1000];
//		int head,tail,lon;
//		public:
//			inline n make(double _x,ll _y){
//				n g;
//				g.x=_x,g.y=_y;
//				return g;
//			}
//			inline n front(){
//				return q[head];
//			}
//			inline n back(){
//				return q[tail-1];
//			}
//			inline void push(const n in){
//				q[tail++]=in,lon++;
//			}
//			inline int size(){
//				return lon;
//			}
//			inline void pop(){
//				lon--,head++;
//			}
//			inline bool empty(){
//				return lon==0?true:false;
//			}
//			inline void clear(){
//				lon=0,head=0,tail=0;
//			}
//	};
//}
namespace scope{
	using namespace std;
	struct big{
		int val,pos;
		bool operator <(const big &op)const{
			return val>op.val;
		}
	};
	struct sml{
		int val,pos;
		bool operator <(const sml &op)const{
			return val<op.val;
		}
	};
	big inbig(int pos,int value){
		big a;
		a.pos=pos,a.val=value;
		return a;
	}
	sml insml(int pos,int value){
		sml a;
		a.pos=pos,a.val=value;
		return a;
	}
	int n,m,k;
	int max_m[1010][1010],min_m[1010][1010],mp[1010][1010];
	inline int read(){
		int s=0,w=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
		return s*w;
	}
	inline void write(int x){
		int y=10,len=1;
		if(x<0)
		{
			x=-x;
			putchar('-');
		}
		while(y<=x)
		{
			y*=10;
			len++;
		}
		while(len--)
		{
			y/=10;
			putchar(x/y+48);
			x%=y;
		}
	}
}
struct node{
    int pos,val;
    bool operator>(const node &tmp)const{return val>tmp.val;};
    bool operator<(const node &tmp)const{return val<tmp.val;};
};
node in(int pos,int value){
	node a;
	a.pos=pos,a.val=value;
	return a;
}
using namespace scope;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
        priority_queue<node,vector<node>,less<node> >que_max;
        priority_queue<node,vector<node>,greater<node> >que_min;
        for(int j=1;j<=k-1;j++){
            que_max.push(in(j,mp[i][j]));
            que_min.push(in(j,mp[i][j]));
        }
        for(int j=k;j<=m;j++){
            que_max.push(in(j,mp[i][j]));
            que_min.push(in(j,mp[i][j]));
            while(que_max.top().pos<=j-k)que_max.pop();
            while(que_min.top().pos<=j-k)que_min.pop();
            max_m[i][j]=que_max.top().val;
            min_m[i][j]=que_min.top().val;
        }
    }
    int ans=2147483645;
    for(int i=1;i<=n-k+1;i++){
        for(int j=k;j<=m;j++){
            int maxx=0,minx=2147483645;
            for(int l=i;l<=i+k-1;l++){
                maxx=max(maxx,max_m[l][j]);
                minx=min(minx,min_m[l][j]);
            }
            ans=min(ans,maxx-minx);
        }
    }
    write(ans);
    return 0;
}
