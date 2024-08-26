#include<iostream>
#include<cstdio>
using namespace std;
int a[17],ans=0,n,b[100]={0},c[100]={0},d[100]={0};
int print()
{
  ans++;
  if(ans<=3){
  	for(int i=1;i<=n-1;i++) printf("%d ",a[i]);
  	printf("%d\n",a[n]);
  }
}
void dfs(int i)
{
	for(int j=1;j<=n;j++)
	{
	  if((!b[j])&&(!c[i+j])&&(!d[i-j+n-1]))
	  {
	  	a[i]=j;
	  	b[j]=1;
	  	c[i+j]=1;
	  	d[i-j+n-1]=1;
	  	if(i==n)print();
	  	else dfs(i+1);
	  	b[j]=0;
	  	c[i+j]=0;
	  	d[i-j+n-1]=0;
	  }
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
