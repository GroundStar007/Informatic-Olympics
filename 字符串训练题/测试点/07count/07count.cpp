#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int i,j,t,tt,lenss,lens;
char s[1000001],ss[11];
int main()
{
	freopen("stat9.in","r",stdin);
	freopen("count.out","w",stdout);
	gets(ss);
	gets(s);
	lens=strlen(s);
	lenss=strlen(ss);
	strlwr(s);
	strlwr(ss);
	for(i=0;i<=lens-lenss;i++)
	{
		for(j=0;j<lenss;j++)
		{
			if(s[i+j]!=ss[j])break;
			if(i>0&&s[i-1]!=' ')break;
		}
		if(j==lenss&&(s[i+j]==' '||i+j==lens))
		{
			t++;
			if(t==1)tt=i;
		}
	} 
	if(t==0)
		printf("-1");
	else
		printf("%d %d",t,tt);
	return 0;
}
