# include<cstdio>
# include<cstring>
using namespace std;
int lena;
char a[40];
int main()
{
//	freopen("delete10.in","r",stdin);
//	freopen("delete10.out","w",stdout);
	gets(a);
	lena=strlen(a);
	if(lena>2&&a[lena-2]=='e'&&a[lena-1]=='r')a[lena-2]=0;
	else if(lena>2&&a[lena-2]=='l'&&a[lena-1]=='y')a[lena-2]=0;
	else if(lena>3&&a[lena-3]=='i'&&a[lena-2]=='n'&&a[lena-1]=='g')a[lena-3]=0;
	puts(a);
	return 0;
}

