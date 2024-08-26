# include<cstdio>
# include<cstring>
using namespace std;
int lena,cnt;
char a[210];
int main()
{
	freopen("password5.in","r",stdin);
	freopen("password5.out","w",stdout);
	gets(a);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			printf("%c",((a[i]-'A')+21)%26+'A');
		else printf("%c",a[i]);
	}
	return 0;
}

