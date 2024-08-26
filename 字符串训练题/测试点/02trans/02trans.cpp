#include<cstdio>
char c;
int main()
{
	freopen("trans5.in","r",stdin);
	freopen("trans5.out","w",stdout);
	c=getchar();
	while(c!='#')
	{
		if(c>='a'&&c<='z')c-=32;
		else c+=32;
		printf("%c",c);
		c=getchar();
	}
	return 0;
}
