#include <iostream>
#include <cstdio>
#include <cstring>
using namespace::std;
int main()
{
	freopen("turn.in.in","r",stdin);
	freopen("turn.out","w",stdout);
	int a,lena,i;
	char a1[10000],a2[10000];
	scanf("%d",&a);
	if(a<0)
	{
		printf("-");
		a*=-1;
	}
	sprintf(a1,"%d",a);
	lena=strlen(a1);
	for(int i=0;i<lena;i++)
	{
		a2[lena-i-1]=a1[i];
	}
	sscanf(a2,"%d",&a);
	cout<<a;
	return 0;
}
