#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double num,num1;
char a[509],b[509];
int len,ans;
int main()
{
	freopen("jene.in","r",stdin);
	freopen("jene.out","w",stdout);
	cin>>num;
	cin.getline(a,501);
	cin.getline(b,501);
	len=strlen(a);
	for(int i=0;i<len;i++)
		if(a[i]==b[i])
			ans++;
	num1=num/(double)ans;
	if(num1>=num)printf("yes");
	else printf("no");
	return 0;
}
