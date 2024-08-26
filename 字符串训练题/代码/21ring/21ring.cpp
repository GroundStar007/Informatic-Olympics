#include <bits/stdc++.h>
using namespace std;
string a,b;
int x,y,len1,len2,minstr,len,ans;
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>a>>b;
	len1=a.size();
	len2=b.size();
    minstr=min(len1,len2);
	a+=a;
	b+=b;
	for(int i=0;i<len1;i++)
		for(int j=0;j<len2;j++)
		{
			len=0;
			x=i;
			y=j;
			while(a[x++]==b[y++]&&len<minstr)len++;
			if(len>ans)ans=len;
		}
	cout<<ans;
	return 0;
}
