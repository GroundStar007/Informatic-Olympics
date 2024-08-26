#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100009;
int m,n,x,y;
queue<int>q;
vector<int>g[N];
bool F[N];

void dfs(int k){
	printf("%d ",k);
	F[k]=1;
	for(int i=0;i<g[k].size();i++)
		if(F[g[k][i]]==false)
			dfs(g[k][i]);
}

void bfs(){
	q.push(1);
	F[1]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		printf("%d ",t);
		for(int i=0;i<g[t].size();i++){
			int h=g[t][i];
			if(F[h]==0){
				q.push(h);
				F[h]=1;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	dfs(1);
	memset(F,0,sizeof(F));
	cout<<endl;
	bfs();
	return 0;
}
