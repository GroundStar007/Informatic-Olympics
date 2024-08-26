#include <bits/stdc++.h>
using namespace::std;
char a,b[1002];
int len1,m;
int main()
{
	freopen("00read.in","r",stdin);
	freopen("00read.out","w",stdout);
	a='c';
	while(a!='\n') //1
	{
		scanf("%s",b);
		a=getchar();
		puts(b);
	}
	cin.getline(b,1000);
	len1=strlen(b);
	for(int i=0;i<len1;i++)//2
		if(b[i]==',') putchar('\n');
		else putchar(b[i]);
	putchar('\n');
	cin>>m;
	for(int i=0;i<m;i++)//3
	{
		scanf("%s",b);
		puts(b);
	}
	scanf("%d ",&m);
	for(int i=0;i<m-1;i++)//4
	{
		cin.getline(b,1000,',');
		puts(b);
	}
	cin.getline(b,1000);
	puts(b);
	scanf("%d\n",&m);
	for(int i=0;i<m;i++)//рт╨С 
	{
		cin.getline(b,1000);
		puts(b);
	}
	return 0;
}
