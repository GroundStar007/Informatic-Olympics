#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[19],b[10000009];
int lena,lenb,o,o1,len[1000009],cnt,j,cnt1,ans,ans1=-1;
bool flag=true;
void IsSmallLetter()
{
	for(int i=0;i<lena;i++) 
		if(a[i]>='A'&&a[i]<='Z') 
			a[i]+=32;
	for(int i=0;i<lenb;i++) 
		if(b[i]>='A'&&b[i]<='Z') 
			b[i]+=32;
}
int main()
{
	freopen("stat.in","r",stdin);
	freopen("stat.out","w",stdout);
	cin.getline(a,11);
	cin.getline(b,10000001);
	lenb=strlen(b);
	lena=strlen(a);
	IsSmallLetter();
	for(int i=0;i<lenb;i++)		
		if(b[i]!=' ')
		{
			o=0;
			for(j=i;b[j]!=' ';j++)o++;	
			if(o==lena)
			{
				len[ans]=i;
				ans++;
			}
			i=j-1;
		}

	for(int i=0;i<ans;i++)
	{
		for(j=len[i],o1=0;o1<lena;j++,o1++)
		{
			flag=true;
			if(a[o1]!=b[j])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			cnt++;
			if(ans1==-1)ans1=len[i];
		}
	}
	if(ans1==-1)printf("-1");
	else printf("%d %d",cnt,ans1);
	return 0;
}
