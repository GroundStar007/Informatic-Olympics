#include <iostream>
#include <cstdio>
#include <cstring>
using namespace::std;
char a[260];
int lena,ans;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin.getline(a,256);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='0'&&a[i]<='9')ans++;
	}
	printf("%d",ans);
	return 0;
}
