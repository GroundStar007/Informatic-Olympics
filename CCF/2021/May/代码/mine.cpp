#include <iostream>
#include <cstdio>
using namespace std;
char a;
int a1[109][109],m,n;
int main()
{
	freopen("mine.in","r",stdin);
	freopen("mine.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			if(a=='*')
			{
				for(int c=i-1;c<=i+1;c++)
					for(int d=j-1;d<=j+1;d++)
					{
						if(a1[c][d]==-1)  continue;
						a1[c][d]++;	
					}
				a1[i][j]=-1;
			}
		}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a1[i][j]==-1)
			{
				cout<<"*";
				continue;
			}
			cout<<a1[i][j];
		}
		if(i!=m)cout<<endl;
	}	
	return 0;
}
