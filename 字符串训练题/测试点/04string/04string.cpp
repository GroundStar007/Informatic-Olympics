#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[10000];
int lena;
int main()
{
	freopen("string2.in","r",stdin);
	freopen("string2.out","w",stdout);
	cin.getline(a,10000);
	lena=strlen(a);
	for(int i=0;i<lena;i++)printf("%c ",a[i]);
	return 0;
}
