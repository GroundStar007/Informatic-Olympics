#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans,tp;
int vis[N],du[N],sta[N];
vector<int> G[N];
void cl()
{
	ans=0;
	for(int i=0;i<=n;i++)vis[i]=du[i]=sta[i]=0;
	for(int i=0;i<=n;i++)vector<int>().swap(G[i]);
}
void dfs(int u)
{
	vis[u]=1;sta[++tp]=u;
	for(auto v:G[u])
		if(!vis[v])dfs(v);
}
int main()
{
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		cl();
		for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				int cnt=0;
				tp=0;
				dfs(i);
				if(tp==1)continue;
				for(int j=1;j<=tp;j++)
					if(G[sta[j]].size()&1)cnt++;
				ans+=max(1,cnt/2);
			}
		printf("%d\n",ans);
	}
	return 0;
}
