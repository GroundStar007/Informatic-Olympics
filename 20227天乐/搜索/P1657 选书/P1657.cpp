#include<iostream>
using namespace std;
int a[100][2],x,cn=0;
bool b[1000]={0};
void dfs(int i)//深搜
{
	if(i>x)
	cn++;//如果所有人都拿到了自己喜欢的书，方案数就加一
	else for(int j=0;j<=1;j++)
		if(!b[a[i][j]])//分别判断每个人喜欢的第一本和第二本书是否被别人拿走，如果没有，就把这本书给这个人
			{
				b[a[i][j]]=1;//把这本书值为已拿过
				dfs(i+1);//拿到书人数加一
				b[a[i][j]]=0;//返回判断第二本
			}
}
int main()
{
	cin>>x;//输入人数
	if(x==0)//特判，测试点应该有这个坑
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=x;i++)
	cin>>a[i][0]>>a[i][1];//输入每个人喜好的书
	dfs(1);
	cout<<cn;
}
