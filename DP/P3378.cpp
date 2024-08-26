#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
long long n, op, x, s[1000009];
priority_queue<ll> q;
int main()
{
	freopen("1.txt","r",stdin);
	scanf("%d", &n);
	while(n --)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%lld", &x);
			q.push(x);
		}
		if (op == 2) printf("%d", q.top());
		if (op == 3 && !q.empty()) q.pop();
	}
	return 0;
}
