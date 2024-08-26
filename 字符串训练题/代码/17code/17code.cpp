#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[59],b[26][2];
int n,ans,lena;
void MakeLetter()
{
	for(char i='a';i<='z';i++)
	{
		b[ans][0]=i;
		if(ans<n)  b[ans][1]='z'+ans-n+1;
		else b[ans][1]=i-n;
		ans++;
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n;
	MakeLetter();
	cin.getline(a,51);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
		for(int j=0;j<26;j++)
			if(a[i]==b[j][1])
			{
				a[i]=b[j][0];
				break;
			}
	puts(a);
	return 0;
}
