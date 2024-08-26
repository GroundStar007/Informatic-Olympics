# include<cstdio>
# include<cstring>
using namespace std;
int i,j;
bool s=true;
char a[100];
int main()
{
	freopen("plalind5.in","r",stdin);
	freopen("plalind5.out","w",stdout);
	gets(a);
	j=strlen(a)-1;
	while(i<j&&s)
	{
		if(a[i]!=a[j])s=false;
		i++;
        j--;	
	}
	if(s==true)printf("yes\n");
	else printf("no\n");
	return 0;
}

