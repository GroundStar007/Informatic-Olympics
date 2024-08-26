#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[40];
int len;
int main()
{
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	cin.getline(a,33);
	len=strlen(a);
	if(a[len-1]=='r'&&a[len-2]=='e')
		for(int i=0;i<len-2;i++)
			cout<<a[i];
	else if(a[len-1]=='y'&&a[len-2]=='l')
		for(int i=0;i<len-2;i++)
			cout<<a[i];
	else if(a[len-1]=='g'&&a[len-2]=='n'&&a[len-3]=='i')
		for(int i=0;i<len-3;i++)
			cout<<a[i];
	else puts(a);
	return 0;
}
