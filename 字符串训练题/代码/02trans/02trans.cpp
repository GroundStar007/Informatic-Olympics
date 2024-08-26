#include <iostream>
#include <cstdio>
using namespace::std;
char a;
int main()
{
	freopen("trans.in.in","r",stdin);
	freopen("trans.out","w",stdout);
	while(cin>>a)
	{
		if(a=='#')break;
		if(a>='A'&&a<='Z')a+=32;
		else if(a>='a'&&a<='z')a-=32;
		cout<<a;
	}
	return 0;
}
