#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N=100010;
vector<int>g[N];
bool f[N];
void dfs(int u)                                       
{//递归
    f[u]=1;                              
    printf("%d ",u);                      
    for(int i=0;i<g[u].size();i++)  
    {
    	int v=g[u][i];
    	if(f[v]==0)//从v开始访问 
    	{
    		dfs(v);
		}
	}
    return;	
}
void bfs()
{
	queue<int>q;
	memset(f,0,sizeof(f));
	q.push(1);
	f[1]=1;
	while(q.size())
	{//出队的顺就是广搜顺序 
		int t=q.front();
		q.pop();
		printf("%d ",t);
		for(int i=0;i<g[t].size();i++)
		{
			int v=g[t][i];
			if(f[v]==0)
			{
				f[v]=1;
				q.push(v);
			}
		 } 
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--)
	{
	   int u,v;
	   scanf("%d%d",&u,&v);
	   g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end());
	}
	dfs(1);
	printf("\n");
	bfs();
	return 0;
}
