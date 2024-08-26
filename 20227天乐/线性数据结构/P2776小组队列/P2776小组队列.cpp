#include<bits/stdc++.h>
using namespace std;
int n,m,t;
string s;//输入的操作指令 
queue<int>xz[310];//每一个小组里面的队列 
queue<int>dl;//dl队列来维护每一个小组的出现顺序 
int a[100010];//存放每一个元素的所在的小组 
int main()
{
   cin>>n>>m;
   for(int i=0;i<n;i++)//从0到n-1输入 
   cin>>a[i];//输入每一个元素所在的小组 
   cin>>t;//输入操作的数量 
   while(t--)
   {
   	cin>>s;
   	if(s[1]=='u')//push操作 
   	{
   		int x;
   		cin>>x;//输入要加入的元素 
   		if(!xz[a[x]].empty())//如果x所在的小组不为空 
   			xz[a[x]].push(x);//放入小组的后面 
   		else//x所在的小组是空的 
   		{
   			dl.push(a[x]);//把当前x的小组放入dl队列，表示x所在的小组有元素了 
   			xz[a[x]].push(x);//把x放入他所在的小组 
   		}
   	}
   	if(s[1]=='o')//pop操作 
   	{
   		int o=dl.front();//取出队头的小组编号 
   		cout<<xz[o].front()<<endl;//输出当前小组的第一个元素 
   		xz[o].pop();//弹出 
   		if(xz[o].empty())//如果当前小组空了 
   		dl.pop();//弹出该小组的编号 
   	}
   }
   return 0;//好习惯 
}
 
