#include <iostream>
#include <cstdio>
using namespace std;
long long a1[100010],summ,i,j;
char a2[100010];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	for(i=0;;i++)
	{
		scanf("%lld%c",&a1[i],&a2[i]);
		if(a2[i]=='\0'||a2[i]=='\n')break;
	}
	for(j=0;j<=i;j++)
		if(a2[j]=='*')
		{
			a1[j+1]*=a1[j];
			a1[j+1]=a1[j+1]%10000;
			a1[j]=0;	
		}
	for(j=0;j<=i;j++)summ+=a1[j];
	printf("%lld",summ%10000);
	return 0;
}
