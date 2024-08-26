#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

const int N = 400009;
ll n, m, x, y, k, h, a[N], c[N], q;
ll tagAdd[N], tagMulti[N];

void buildTree(int pos, int l, int r)
{
	tagMulti[pos] = 1;
	if (l == r)
	{
		c[pos] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	buildTree(pos * 2, l, mid);
	buildTree(pos * 2 + 1, mid + 1, r);
	c[pos] = c[pos * 2] + c[pos * 2 + 1];
}

ll calculate(int pos, int l, int r, int s, int t, ll p)
{
	p += tagAdd[pos];
	if(l == s && r == t) return c[pos] + p * (t - s + 1);
	int mid = (l + r) / 2;
	if (mid >= t) 
		return Calculate(pos * 2, l, mid, s, t, p);
	else if (mid < s) 
		return Calculate(pos * 2 + 1, mid + 1, r, s, t, p);
	else 
		return Calculate(pos * 2, l, mid, s, mid, p) 
			 + Calculate(pos * 2 + 1, mid + 1, r, mid + 1, t, p);
}

void multiply(int pos, int l, int r, int s, int t, )

void add(int pos, int l ,int r, int s, int t, int k)
{
	if (l == s && r == t) 
	{
		tagAdd[pos] += k;
		return;
	}
	c[pos] += k * (t - s + 1);
	int mid = (l + r) / 2;
	if (mid >= t) add(pos * 2, l, mid, s, t, k);
	else if (mid < s) add(pos * 2 + 1, mid + 1, r, s, t, k);
	else add(pos * 2, l, mid, s, mid, k),
		 add(pos * 2 + 1, mid + 1, r, mid + 1, t, k);
}

int main()
{
	freopen("1.txt", "r", stdin);
	scanf("%lld%lld", &n, &m, &q);
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	buildTree(1, 1, n);
	while(m --)
	{
		scanf("%lld", &h);
		if (h == 1) 
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			multiply(1, 1, n, x, y, k);
		}
		if (h == 2)
		{
			scanf("%lld%lld", &x, &y);
			add(1, 1, n, x, y, k);
		}
		if (h == 3)
		{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", calculate(1, 1, n, x, y, k));
		}
	}
	return 0;
}
