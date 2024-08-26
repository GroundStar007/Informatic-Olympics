#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[30];
int lena,l,r,cnt;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++)
	{
		sprintf(a,"%d",i);
		lena=strlen(a);
		for(int j=0;j<lena;j++)if(a[j]=='2')cnt++;
	}
	printf("%d ",cnt);
	return 0;
}
