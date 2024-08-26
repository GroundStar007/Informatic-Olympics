#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[30],b[30];
int n,lena;
int main()
{
	freopen("turn.in","r",stdin);
	freopen("turn.out","w",stdout);
	scanf("%d",&n);
	sprintf(a,"%d",n);
	lena=strlen(a);
	for(int i=0,j=lena-1;i<lena;i++,j--)b[i]=a[j];
	if(n<0)putchar('-');
	sscanf(b,"%d",&n);
	printf("%d",n);
	return 0;
}
