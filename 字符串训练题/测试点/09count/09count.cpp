# include<cstdio>
# include<cstring>
using namespace std;
int lena,cnt;
char a[260];
int main()
{
	freopen("count5.in","r",stdin);
	freopen("count5.out","w",stdout);
	gets(a);
	lena=strlen(a);
	for(int i=0;i<lena;i++)
		if(a[i]>='0'&&a[i]<='9')cnt++;
	printf("%d",cnt);
	return 0;
}

