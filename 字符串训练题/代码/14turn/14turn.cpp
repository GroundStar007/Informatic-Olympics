#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a,b[509];
int lenb;
int main()
{
	freopen("turn.in","r",stdin);
	freopen("turn.out","w",stdout);
	while(1!=0)
	{
		scanf("%c",&a);
		if(a=='\0'||a=='\n')break;
		if(a!=' ')
		{
			scanf("%s",b);
			lenb=strlen(b);
			for(int i=lenb-1;i>=0;i--)cout<<b[i];
			cout<<a;
		}
		else if(a==' ')
			cout<<" ";
	}
	return 0;
}
