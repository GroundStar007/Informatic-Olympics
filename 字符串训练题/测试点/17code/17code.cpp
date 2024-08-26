# include<cstdio>
# include<cstring>
using namespace std;
int lena,cnt,n;
char a[60];
int main()
{
	freopen("code5.in","r",stdin);
	freopen("code5.out","w",stdout);
	scanf("%d\n",&n);
	gets(a);
	lena=strlen(a);
	for(int i=0;i<lena;i++)printf("%c",((a[i]-'a')+n)%26+'a');
	return 0;
}

