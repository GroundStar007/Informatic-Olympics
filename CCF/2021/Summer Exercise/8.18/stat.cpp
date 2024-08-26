#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[19],b[1000009];
int lena,lenb,o,o1,len[1000009],cnt,j,cnt1,ans,ans1= -1;
bool flag=true;
int main()
{
	cin.getline(a,19);
	cin.getline(b,1000009);
	lenb=strlen(b);
	lena=strlen(a);
	for(int i=0;i<lenb;i++)		
		if(b[i]!=' ')
		{
			o=0;
			for(j=i;j<lenb&&b[j]!=' ';j++)o++;	//此处越界，我已修改 
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
			if(a[o1]!=b[j]&&a[o1]-b[j]!=32&&a[o1]-b[j]!=-32)
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
