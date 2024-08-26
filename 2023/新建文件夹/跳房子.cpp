#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int n,d,k;
const int N=500010;
int dis[N],num[N];
long long b[N];
bool  check(int g)
{
	memset(b,128,sizeof(b));
	//cout<<b[0]<<endl; 
	int l=max(1,d-g);
	int r=d+g;
	deque<int>dq;
	int now=0;
	b[0]=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(dis[now]+l<=dis[i])
		{
			while(dq.size()&&b[dq.back()]<=b[now])
			{
				dq.pop_back();
			}
			dq.push_back(now);
			now++;
		}
		while(dq.size()&&dis[dq.front()]+r<dis[i])
		{
			dq.pop_front();
		}
		if(dq.size())b[i]=b[dq.front()]+num[i];
		ans=max(ans,b[i]);
		//cout<<b[i]<<endl;
		if(ans>=k)return true;
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&dis[i],&num[i]);
	}
	int l=0,r=1e9+1;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl; 
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l==1e9+1)printf("-1");
	else cout<<l;//最小的花费 
	return 0;
 } 
