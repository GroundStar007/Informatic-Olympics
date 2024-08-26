#include <bits/stdc++.h>
using namespace std;
string s,s1,s2;
int dis1,dis2,lens1,lens2;
int main()
{
	freopen("span.in","r",stdin);
	freopen("span.out","w",stdout);
	getline(cin,s,',');
	getline(cin,s1,',');
	getline(cin,s2);
	lens1=s1.size();
	lens2=s2.size();
	dis1=s.find(s1);
	dis2=s.rfind(s2);
	if(dis1+lens1<dis2)cout<<dis2-1-(dis1+1);
	else cout<<"-1";
	return 0;
}
