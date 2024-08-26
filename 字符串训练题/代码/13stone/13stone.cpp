#include <iostream>
#include <cstdio>
using namespace std;
int n;
char a[100],b[100];
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s%s",a,b);
		if(a[0]==b[0])cout<<"Tie";
		else if(a[0]=='R')
		{
			if(b[0]=='S')cout<<"Player1";
			else if(b[0]=='P')cout<<"Player2";
		}
		else if(a[0]=='S')
		{
			if(b[0]=='R')cout<<"Player2";
			else if(b[0]=='P')cout<<"Player1";
		}
		else if(a[0]=='P')
		{
			if(b[0]=='S')cout<<"Player2";
			else if(b[0]=='R')cout<<"Player1";
		}
	}
	return 0;
}
