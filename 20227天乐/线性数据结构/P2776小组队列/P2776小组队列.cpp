#include<bits/stdc++.h>
using namespace std;
int n,m,t;
string s;//����Ĳ���ָ�� 
queue<int>xz[310];//ÿһ��С������Ķ��� 
queue<int>dl;//dl������ά��ÿһ��С��ĳ���˳�� 
int a[100010];//���ÿһ��Ԫ�ص����ڵ�С�� 
int main()
{
   cin>>n>>m;
   for(int i=0;i<n;i++)//��0��n-1���� 
   cin>>a[i];//����ÿһ��Ԫ�����ڵ�С�� 
   cin>>t;//������������� 
   while(t--)
   {
   	cin>>s;
   	if(s[1]=='u')//push���� 
   	{
   		int x;
   		cin>>x;//����Ҫ�����Ԫ�� 
   		if(!xz[a[x]].empty())//���x���ڵ�С�鲻Ϊ�� 
   			xz[a[x]].push(x);//����С��ĺ��� 
   		else//x���ڵ�С���ǿյ� 
   		{
   			dl.push(a[x]);//�ѵ�ǰx��С�����dl���У���ʾx���ڵ�С����Ԫ���� 
   			xz[a[x]].push(x);//��x���������ڵ�С�� 
   		}
   	}
   	if(s[1]=='o')//pop���� 
   	{
   		int o=dl.front();//ȡ����ͷ��С���� 
   		cout<<xz[o].front()<<endl;//�����ǰС��ĵ�һ��Ԫ�� 
   		xz[o].pop();//���� 
   		if(xz[o].empty())//�����ǰС����� 
   		dl.pop();//������С��ı�� 
   	}
   }
   return 0;//��ϰ�� 
}
 
