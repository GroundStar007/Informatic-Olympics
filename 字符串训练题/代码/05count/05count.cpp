#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char ans1[10000];
int b1,b2,ans,len1;
int main()
{
	freopen("count.in.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&b1,&b2);
	for(int i=b1;i<=b2;i++)
	{
		sprintf(ans1,"%d",i);
		len1=strlen(ans1);
		for(int i=0;i<len1;i++)
		{
			if(ans1[i]=='2')ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
