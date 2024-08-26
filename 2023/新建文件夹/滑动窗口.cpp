//保持队头一定最大值   最小值

//   1 1 2 3 4 3 
//   双端队列：队头一定存放最小值 或者最大值。  m
//   从队头出队的一定不满足长度要求的。
//   从队尾出去的一定失效的数据。

#include <iostream>
#include <deque>
using namespace std;
const int N=1000010;
int a[N];
deque<int>dq;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(dq.size()&&a[dq.back()]>=a[i])
		{
		    dq.pop_back();	
		}
		dq.push_back(i);
		//从队头出队
		while(i-dq.front()>=k)dq.pop_front();
		if(i>=k)
		{
			printf("%d ",a[dq.front()]);
		} 
	}
	printf("\n");
	dq.clear();
	for(int i=1;i<=n;i++)
	{
		while(dq.size()&&a[dq.back()]<=a[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
		while(i-dq.front()>=k)dq.pop_front();
		if(i>=k)
		{
			printf("%d ",a[dq.front()]);
		}
	}
	return 0;
 }  
