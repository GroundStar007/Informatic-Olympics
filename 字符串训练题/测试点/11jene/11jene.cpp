# include<cstdio>
# include<cstring>
using namespace std;
int lena,cnt;
char a[510],b[510];
double s;
int main()
{
	freopen("jene3.in","r",stdin);
	freopen("jene3.out","w",stdout);
	scanf("%lf\n",&s);
	gets(a);
	gets(b);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
		if(a[i]==b[i])cnt++;
	if(cnt*1.0/lena>=s)printf("yes");
	else printf("no");
	return 0;
}

