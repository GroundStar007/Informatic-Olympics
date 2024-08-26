#include <iostream>
using namespace std;
const int N=1010; 
int p[N]; 
int find(int x)
{
	if(p[x]!=x)
	p[x]=find(p[x]);
	return p[x];
}
void merge(int x,int y)
{
	int a=find(x);
	int b=find(y);
	if(a!=b)
	p[a]=b;
 } 
bool judge(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	
	return 0;
}
