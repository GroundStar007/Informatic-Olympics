
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int>g[100009];
int n,m,u,v,vis[100009];

void dfs(int x,int h){
	if(vis[x])return;
	vis[x]=h;
	for(int i=0;i<g[x].size();i++)
		dfs(g[x][i],h);
}

int main(){
// 	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		g[v].push_back(u);  // ����ͼ����Ϊ�Ӵ����С������
	}
	for(int i=n;i>=1;i--)dfs(i,i);
	for(int i=1;i<=n;i++)printf("%d ",vis[i]);
	return 0;
}
