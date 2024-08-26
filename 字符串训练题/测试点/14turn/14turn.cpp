#include<iostream>
#include<cstdio>
#include<cstring> 
#include<stack> 
using namespace std; 
stack<char>s; 
char c[600]; 
void chuzhan()
{
	while(!s.empty())
	{ 
		cout<<s.top(); 
		s.pop();
	} 
}
int main()
{ 
	freopen("turn5.in","r",stdin);
	freopen("turn5.out","w",stdout);
	cin.getline(c,600);
	int lenc=strlen(c);
	for(int i=0;i<lenc;i++) 
	{ 
		if(c[i]!=' ')s.push(c[i]);
		else
		{
			chuzhan();
			cout<<" "; 
		} 
	} 
	chuzhan();
	return 0; 
} 

