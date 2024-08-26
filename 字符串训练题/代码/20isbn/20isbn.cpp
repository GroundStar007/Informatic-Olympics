#include <bits/stdc++.h>
using namespace std;
string a1,a2,a3,a;
long long n,n1;
int main()
{
	freopen("isbn.in","r",stdin);
	freopen("isbn.out","w",stdout);
	getline(cin,a1,'-');
	getline(cin,a2,'-');
	getline(cin,a3,'-');
	cin>>n;
	a=a1+a2+a3;
	for(long long i=0;i<9;i++)
	{
		n1+=(a[i]-48)*(i+1);
	}
	if(n1%11==n)cout<<"Right";
	else
	{
		a.insert(1,"-");
		a.insert(5,"-");
		a+="-";
		for(int i=0;i<12;i++) cout<<a[i];
		cout<<n1%11;
	}
	return 0;
}
