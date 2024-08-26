//   从第1个格子开始跳，到达第i个格子的最大值。 b[i]
//    求： num[i]
//     求  dis[i]-r   dis[i]-l 之间这些各自的最大值j
//        b[i]=b[j]+num[i]; 
//   求一个区间的最大值  最小值   单调队列 

#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
const int N=500010;
long long b[N];//b[i]:从起点到达第i个格子的分数。 
deque<int>dq; 
int dis[N],num[N];//保存输入的数据  dis[i]:从起点到第i个点的距离
int main()
{
  memset(b,128,sizeof(b));
  int n,l,r;
  cin>>n>>l>>r;
  for(int i=1;i<=n;i++)
  {
  	scanf("%d %d",&dis[i],&num[i]); 
  }
  b[0]=0;
  int now=0;
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
     //所有dis[now]+L<=dis[i]的格子入队
	 while(dis[now]+l<=dis[i])
	 {
	       //now入队之前
		   while(dq.size()&&b[dq.back()]<=b[now])
		   {
		   	   dq.pop_back();
		   }
		   dq.push_back(now);
		   now++; 
	 }	
	 //出队  dis[dq.front()]+r<dis[i]
	    while(dq.size()&&dis[dq.front()]+r<dis[i])
		{
			dq.pop_front();
		} 
		//队列所有的格子 都是 dis[j]+l<=dis[i]  dis[j]+r>=dis[i]
		if(dq.size())b[i]=b[dq.front()] + num[i];
		ans=max(ans,b[i]);
  }	
  cout<<ans;
  return 0;
} 
