#include <iostream>
#include <cstdio>
using namespace::std;
char a='a';
int main()
{
	freopen("char.in.in","r",stdin);
	freopen("char.out","w",stdout);
	for(char i='a';i<='z';i+=2)
		cout<<i<<" ";
	cout<<endl;
	for(char i='z';i>'a';i-=2)
		cout<<i<<" ";
	return 0;
}
