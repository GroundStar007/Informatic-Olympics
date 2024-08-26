#include <bits/stdc++.h>
using namespace std;
string s,a,b,n;
int lena,lenb,lens,o,j,ans;
bool flag=true;
int main()
{
	getline(cin,s);
	getline(cin,a);
	getline(cin,b);
	lena=a.size();
	while(1!=0)
	{
		ans=s.find(a);
		if(ans==-1)break;
		s.erase(ans,ans+lena);
		s.insert(ans,b);
	}
	puts(s.c_str());
	return 0;
}
