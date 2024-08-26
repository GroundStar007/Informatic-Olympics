# include<cstdio>
# include<iostream>
# include<cstring>
using namespace std;
int lena,lenb,ansa=1,ansb=1,n;
char a[10],b[10];
int main()
{
	freopen("ufo6.in","r",stdin);
	freopen("ufo6.out","w",stdout);
	cin.getline(a,10);
	cin.getline(b,10);
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=0;i<lena;i++)ansa*=a[i]-'A'+1;
	for(int i=0;i<lenb;i++)ansb*=b[i]-'A'+1;
	if(ansa%47==ansb%47)printf("GO");
	else printf("STAY");
	return 0;
}

