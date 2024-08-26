#include <iostream>
#include <cstdio>
using namespace std;
int a,b,cnt,sum,n,d[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=12;i++)
		for(int j=1;j<=d[i];j++)
		{
			n=(j%10)*1000+(j/10)*100+(i%10)*10+(i/10);
			sum=n*10000+i*100+j;
			if(sum<a||sum>b)  continue;
			cnt++;
		}
	cout<<cnt;
	return 0;
}
