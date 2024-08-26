#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[10],b[10];
long long n,n1=1,n2=1,lena,lenb;
int main()
{
	freopen("ufo.in","r",stdin);
	freopen("ufo.out","w",stdout);
	scanf("%s",a);
	scanf("%s",b);
	lena=strlen(a);
	lenb=strlen(b);
	for(long long i=0;i<lena;i++)
		n1*=(a[i]-64);
	for(long long i=0;i<lenb;i++)
		n2*=(b[i]-64);
	if(n1%47==n2%47)cout<<"GO";
	else cout<<"STAY";
	return 0;
}
