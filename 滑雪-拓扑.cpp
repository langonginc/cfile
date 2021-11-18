#include<fstream>
using namespace std;
ifstream fin("hx.txt");
ofstream fout("hxtp.txt");
int a[502][502],f[502][502],r[502][502];
int main(){
	int i,j,n,m,z=0,b[100001],c[100001],x,y,s,t,max=0,u[4]={-1,1,0,0},v[4]={0,0,-1,1};
	fin>>n>>m;
	memset(r,1,sizeof(r));
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	fin>>a[i][j];
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
	//找入度为0 //r[i][j]就是逆邻接计数器
		r[i][j]=(a[i+1][j]>a[i][j])+(a[i-1][j]>a[i][j])+(a[i][j+1]>a[i][j])+(a[i][j-1]>a[i][j]);
		if(r[i][j]==0){
			z++;
			b[z]=i;
			c[z]=j;
		}
	}	
	while(z>0){
		x=b[z];
		y=c[z];
		z--;   //删除此结点 
		for(i=0;i<4;i++){
			s=x+u[i];
			t=y+v[i];
			if(a[x][y]>a[s][t]){
				r[s][t]--;//删除与该结点相连的出边，即让其入度减1 
				if(f[x][y]>=f[s][t])
				f[s][t]=f[x][y]+1;
				if(r[s][t]==0)
				{z++;
				b[z]=s;
				c[z]=t;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		  if(f[i][j]>max)
		    max=f[i][j];
	fout<<max+1<<endl;
	return 0;
}
