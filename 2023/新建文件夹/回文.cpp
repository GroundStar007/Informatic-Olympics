//dfs 关键传什么参数
#include <iostream>
#include <string>
using namespace std;
string ans;
int n;
const int N=5e5+10;
int a[2*N],b[2*N];
bool f;
void dfs(int pos,int l,int r,string str)
{
	if(f)return;
    if(pos>2*n)  // if(l>r)
    {//b一定组成了一个长度为2*n的序列 
      //判断b是否是一个会问序列
      bool flg=true;
	  for(int i=1;i<=2*n;i++)
	  {
	    if(b[i]!=b[2*n-i+1])  
		{
			flg=false;
			break;
		}	
	  }
	  if(flg)
	  {
	  	  f=true;
	      ans=min(ans,str);	
	  }	
	  return ;
	}
	b[pos]=a[l];
	dfs(pos+1,l+1,r,str+'L');
	b[pos]=a[r];
	dfs(pos+1,l,r-1,str+'R');	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans="Z";
	f=false;
	dfs(1,1,2*n,"");
	if(f)
	{
		printf("%s\n",ans.c_str());
	}
	else
	{
		printf("-1\n");
	}
	}
return 0;
}
