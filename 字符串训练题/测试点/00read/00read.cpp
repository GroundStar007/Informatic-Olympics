#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,lena;
char x,a[1002];
int main()
{
//	freopen("read.in","r",stdin);
//	freopen("read.out","w",stdout);
	x='a';
	while(x!='\n')//��һ�� 
	{
		scanf("%s",a); 
		x=getchar();
		puts(a);
	}
	gets(a);//�ڶ��� 
	lena=strlen(a);
	for(int i=0;i<lena;i++)
		if(a[i]==',')putchar('\n');
		else putchar(a[i]);
	putchar('\n');
	scanf("%d",&n);//������ 
	for(int i=0;i<n;i++)
	{
		scanf("%s",a); 
		puts(a);
	} 
	scanf("%d ",&n);//������ 
	for(int i=0;i<n-1;i++)
	{
		cin.getline(a,1000,',');
		puts(a);
	}
	cin.getline(a,100);
	puts(a);
	scanf("%d\n",&n);//���n�� 
	for(int i=0;i<n;i++)
	{
		gets(a);
		puts(a);
	}
	return 0;
}
