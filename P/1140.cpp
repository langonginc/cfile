#include<iostream>
#include<string>
using namespace std; 
int max(int x,int y){ 
   if(x>y)   
        return x;
   else    
       return y;} 
int main(){   
    int calculate[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};//题设所给相似度表格
	int a,b;//基因长度    
	string gene_a,gene_b;//基因序列    
	int num_a[110],num_b[110];//用于将基因序列转为编码存储的数组    
	int dp[110][110]={0};//初始化    
	int i,j;        
	cin>>a>>gene_a;//基因序列a    
	cin>>b>>gene_b;//基因序列b     
	for(int i=1;i<=a;i++)      
		for(int j=1;j<=b;j++)     
		   dp[i][j]=~0x3f; //初始化为一极小值            
	for(i=1;i<=a;i++){//将基因序列a转为题设所给相似度表格中的数字代码    
	   if(gene_a[i-1]=='A')	num_a[i]=0;        
	   if(gene_a[i-1]=='C')	num_a[i]=1;        
	   if(gene_a[i-1]=='G')	num_a[i]=2;        
	   if(gene_a[i-1]=='T')	num_a[i]=3;    }    
	for(i=1;i<=b;i++){//将基因序列b转为题设所给相似度表格中的数字代码       
	   if(gene_b[i-1]=='A')	num_b[i]=0;        
	   if(gene_b[i-1]=='C')	num_b[i]=1;       
	   if(gene_b[i-1]=='G')	num_b[i]=2;        
	   if(gene_b[i-1]=='T')	num_b[i]=3;    }   
    /*        特判情况        
	第一个基因第1个与第二个基因第0个匹配时，与空碱基匹配的值相同，
	可视为与空碱基匹配        
	同理，第二个基因第1个与第一个基因第0个匹配时，与空碱基匹配的值相同    */    
	for(i=1;i<=a;i++)
		dp[i][0]=dp[i-1][0]+calculate[num_a[i]][4];
    for(i=1;i<=b;i++)
		dp[0][i]=dp[0][i-1]+calculate[num_b[i]][4];     
	/*        比较碱基对相似度，共三种情况：    	
	①不插入空碱基，直接进行配对        
	②序列a不变，在序列b中插入空碱基        
	③序列b不变，在序列a中插入空碱基    */    
	for(i=1;i<=a;i++) {   
	     for(j=1;j<=b;j++){         
		    dp[i][j]=max( dp[i][j] , dp[i][j-1]+calculate[ num_b[j] ][4] );
			//序列a中插空碱基		            
			dp[i][j]=max( dp[i][j] , dp[i-1][j]+calculate[ num_a[i] ][4] );
			//序列b中插空碱基            
			dp[i][j]=max( dp[i][j] , dp[i-1][j-1]+calculate[ num_a[i] ][ num_b[j] ] );//不插入直接配对        
		}    
	}        
	cout<<dp[a][b];    
	return 0;
}
