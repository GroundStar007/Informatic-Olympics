#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N=100009;
int n,m,qq,u,v,q1,dis[N];
vector<int>g[N];
queue<int>q;
bool F[N];

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&qq);
	while(m--){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	q.push(1);
	F[1]=true;
	dis[1]=0;
	while(!q.empty()){
		int d=q.front();
		q.pop();
		for(int i=0;i<g[d].size();i++){
			if(F[g[d][i]]==false){
				q.push(g[d][i]);
				F[g[d][i]]=true;
				dis[g[d][i]]=dis[d]+1;
			}
		}
	}
	
	while(qq--){
		scanf("%d",&q1);
		if(F[q1]==0)printf("No\n");
		else printf("%d\n",dis[q1]);
	}
	return 0;
}
