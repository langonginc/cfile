#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
using namespace std;
struct emd{
	int step;
	int p,x,y;//p,空白格顺序号；x,y空白格坐标，1起始
	string s;
	emd(int step,int p,int x,int y,string s):step(step),p(p),x(x),y(y),s(s){}
};
string endstr="123456780";//目的结果
string start[35];// 起点状态数组
int cx[4]={0,0,-1,1};
int cy[4]={-1,1,0,0};


/*
int main(){
	string start;
    int N;
    cin >> N;
    while (N --)
    {
        start = "";
        string now = "";
        for (int i = 0; i < 3; i ++)
        {
            for (int j = 0; j < 3; j ++)
            {
                int x;
                cin >> x;
                char ch = x + '0';
                start = start + ch;
            }
        }
        // cout<<start;
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
    		now=d.s;
    		int beforep=d.p;
    		int beforex=d.x;
    		int beforey=d.y;
    		if(d.s==send){
            // if (strcmp(d.s.c_str(), send.c_str()) == 0){
    			cout<<d.step<<endl;
                break;
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
        // cout << "NO RESULT";
    }
	return 0;
}
*/

int main ()
{
    int N;
    cin >> N;
    for (int t = 1; t <= N; t ++)
    {
        start[t] = "";
        for (int i = 0; i < 3; i ++)
        {
            for (int j = 0; j < 3; j ++)
            {
                int x;
                cin >> x;
                char ch = x + '0';
                start[t] += ch;
            }
        }
    }
    queue<emd>q;
    map<string, int> mp;
    set<string>r;
    r.insert(endstr);
    int anscount = 0;
    string now;
    for(int i=0;i<9;i++){
        if(endstr[i]=='0'){
            q.push(emd(0,i,i/3,i%3,endstr));
        }
    }
    while(!q.empty()){
        emd d=q.front();
        q.pop();
        now=d.s;
        int beforep=d.p;
        int beforex=d.x;
        int beforey=d.y;
        // if(d.s==send){
        // // if (strcmp(d.s.c_str(), send.c_str()) == 0){
        //     cout<<d.step<<endl;
        //     break;
        // }
        for (int i = 1; i <= N; i ++)
        {
            if (d.s == start[i])
            {
                mp[start[i]] = d.step;
                anscount ++;
            }
            if (anscount >= N)
            {
                break;
            }
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
    for (int i = 1; i <= N; i ++)
    {
        cout << mp[start[i]] << endl;
    }
    return 0;
}
