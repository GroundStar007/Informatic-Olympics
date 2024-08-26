#include <iostream>
#include <cstdio>
#include <cstring>
using namespace::std;
char a[209],b[26][2];
int lena,ans;
int main()
{
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	for(char i='A';i<='Z';i++)
	{
		b[ans][0]=i;
		if(ans<5)
		{
			b[ans][1]='Z'+ans-4;
		}
		else b[ans][1]=i-5;
		ans++;
	}
	cin.getline(a,201);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			for(int j=0;j<26;j++)
				if(b[j][0]==a[i])
				{
					a[i]=b[j][1];
					break;	
				}			
	}
	puts(a);
	return 0;
}
