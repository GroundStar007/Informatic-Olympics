#include <iostream>
#include <cstdio>
#include <cstring>
using namespace::std;
char a[100];
int main()
{
	freopen("plalind.in","r",stdin);
	freopen("plalind.out","w",stdout);
	int lena,c;
	bool flag=true;
	cin.getline(a,101);
	lena=strlen(a);
	if(lena%2==0)
	{
		c=lena;
		c/=2;
		for(int i=0;i<c;i++)
			if(a[i]!=a[lena-i-1])
			{
				flag=false;
				break;
			}
		if(flag==true)
		{
			printf("yes");
			return 0;
		}
	}
	else if(lena%2==1)
	{
		c=lena;
		c-=1,c/=2;
		for(int i=0;i<c;i++)
			if(a[i]!=a[lena-i-1])
			{
				printf("no");
				return 0;
			}
		if(flag==true)
		{
			printf("yes");
			return 0;
		}
	}
	printf("no");
	return 0;
}
