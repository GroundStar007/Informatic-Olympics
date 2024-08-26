#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string c[4][4]={{"Tie","","Player1","Player2"},
				{"","","",""},
				{"Player2","","Tie","Player1"},
				{"Player1","","Player2","Tie"}};
char a[10],b[10];
int n;
int main()
{
	freopen("stone1.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%s%s",a,b);
		cout<<c[a[0]-'P'][b[0]-'P']<<endl;
	}
	return 0;
}

