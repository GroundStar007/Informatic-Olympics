#include <iostream>
#include <stack>
using namespace std;
stack<int>st;
const int N=100010; 
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	long long ans=0;
	a[n+1]=1e5+1;
	for(int i=1;i<=n+1;i++)
	{
		int j;
		while(st.size()&&a[st.top()]<=a[i])
		{
			j=st.top();
			st.pop();
			ans=ans+(i-j-1);
		}
		st.push(i);	   	
	} 
	cout<<ans;
	return 0;
 } 
