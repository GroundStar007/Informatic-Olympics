#include <iostream>
#include <cstdio>
#include <cstring>
using namespace::std;
int main()
{
	freopen("string.in.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[10000];
	int lena;
	cin.getline(a,10000);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
