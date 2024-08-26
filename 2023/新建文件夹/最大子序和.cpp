//   1 1 2 3 4 3 
//   双端队列：队头一定存放最小值 或者最大值。  m
//   从队头出队的一定不满足长度要求的。
//   从队尾出去的一定失效的数据。

#include <iostream>
#include <deque>
using namespace std;
const int N=300010;
int s[N],a[N];
deque<int>dq;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];  //s[0]=0
	}
	dq.push_back(0);
	int ans=s[1];
	for(int i=1;i<=n;i++)
	{
		//先找s[0]-s[i-1]之间的一个最小值
		while(i-dq.front()>m)//把队头不满足长度要求的出队处理 
		{
			dq.pop_front();
	    }//上面的while循环是从队头出队 
		ans=max(ans,s[i]-s[dq.front()]);
		//从队尾入队
		while(dq.size()&&s[dq.back()]>=s[i])
		{
			dq.pop_back();
		} 
		dq.push_back(i);
	}
	cout<<ans;
	return 0;
 } 
