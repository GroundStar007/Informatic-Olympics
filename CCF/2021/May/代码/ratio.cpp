#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double a,b,c,d,minn=0x7fffffff,a1,b1,l,r;
int a2,b2; 
int main()
{
	freopen("ratio.in","r",stdin);
	freopen("ratio.out","w",stdout);
	scanf("%lf%lf%lf",&a,&b,&l);
//	printf("%lf",a/b);
	c=a/b;
	for(double i=1;i<=l;i++)
		for(double j=1;j<=l;j++)
		{
			d=i/j-c;
			if(d<minn&&d>=0)
			{
				a1=i;
				b1=j;
				minn=d;
			}
		}
	a2=(int)a1;
	b2=(int)b1;
	printf("%d %d",a2,b2);
	return 0;	
}
