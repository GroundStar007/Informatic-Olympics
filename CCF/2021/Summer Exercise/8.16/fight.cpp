#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;
long long a[100011];
int main()
{
    freopen("8.16.txt","r",stdin);
	long long nong=0,hu=0;
	int i,n;
	long long m,s1,p1,p2;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%lld %lld %lld %lld",&m,&p1,&s1,&p2);
	a[p1]+=s1;   
	for(i=1;i<=n;i++)
	{
		if(i<m) nong+=a[i]*(m-i);   //统计龙方的气势值
		else if(i>m) hu+=a[i]*(i-m); //统计虎方的气势值
	}
	long long ans=abs(nong-hu);    //ans初始化为将工兵放在m号兵营里面
	int step=m;   //最小号兵营一开始赋值为m号兵营
	for(i=1;i<=n;i++)
	{
		if(i<m) //在m号兵营左边加龙方的气势值
		{
			if(ans>abs((nong+p2*(m-i)-hu)))
			{
				ans=abs((nong+p2*(m-i)-hu));
				step=i;
			}
		}
		else if(i>m) //在m号兵营左边加龙方的气势值
		{
			if(ans>abs(nong-(hu+p2*(i-m))))
			{
				ans=abs(nong-(hu+p2*(i-m)));
				step=i; 
			}
		}
	}
	cout<<step;
	return 0;
}