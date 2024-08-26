#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n, a[3000009], f[3000009];
stack<int> s;
int main()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++)
	{
		while (!s.empty() && a[s.top()] <= a[i])
			s.pop();
		if(!s.empty())f[s.top()] = i;
		s.push(i); 
	}
	for (int i = 1; i <= n; i ++)
		printf ("%d ", f[i]);
	return 0;
}
