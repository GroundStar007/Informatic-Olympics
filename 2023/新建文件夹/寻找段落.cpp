#include <iostream>
#include <deque>
using namespace std;
const int N=100010;
int n,S,t,a[N];
double b[N],s[N];
bool check(double x)
{
	deque<int>dq;
	double ans=-10000;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-x;
		s[i]=s[i-1]+b[i];
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=S)
		{
			while(dq.size()&&s[dq.back()]>=s[now])
			{
				dq.pop_back();
			}
			dq.push_back(now);
			now++;
		}
		while(dq.size()&&i-dq.front()>t)dq.pop_front();
		if(dq.size())
		{
			ans=max(ans,s[i]-s[dq.front()]);
			if(ans>=0)return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&S,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	double l=-10000,r=10000;
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(check(mid))
		{//当有一段的平均值满足要求 
			l=mid; 
	    }
	    else
	    {
	    	r=mid;
		}
	}
	printf("%.3f",l);
	return 0;
}
