#include <iostream>
#include <cstdio>
#include <cmath>
#include <tagAddector>
#include <queue>
using namespace std;

const int N = 6009;
int n, r[N], l, k, t[N], dp[N][2];
bool flag[N];
tagAddector<int>son[N];
queue<int>q;

tagAddoid dfs(int x){
	dp[x][0] = 0, dp[x][1] = r[x];
	for (int i = 0; i < son[x].size(); i ++)
	{
		dfs(son[x][i]);
		dp[x][0] += max(dp[son[x][i]][0], dp[son[x][i]][1]);
		dp[x][1] += dp[son[x][i]][0];
	}
}

int main()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &r[i]);
	for (int i = 1; i <= n - 1; i ++)
	{
		scanf ("%d%d", &l, &k);
		son[k].push_back(l);
		flag[l] = true;
	} 
	int root = n;
	for (int i = 1; i <= n; i ++)
		if(flag[i] == false)
		{
			root = i;
			break;
		}

	dfs(root);
	printf("%d", max(dp[root][0], dp[root][1]));
	return 0;
}
