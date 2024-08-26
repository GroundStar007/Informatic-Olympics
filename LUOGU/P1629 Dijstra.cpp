#include <iostream>
#include <cstdio>
#include <queue>
#define INF 1e9
using namespace std;
int min(int a,int b){return a<b?a:b;}

struct Node{
	int d,u;
	bool operator<(const Node&r)const{
		return d>r.d;
	}
};
int m,n,u,v,w,ans;
int c[1009][1009],dis[1009];
priority_queue<Node>q;

inline void Dijsktra(){
	for(int i=1;i<=n;i++)dis[i]=c[1][i];
	bool vis[1009]={false};
	vis[1]=true;
	q.push((Node){dis[1],1});
	while(!q.empty()){
		Node p=q.top();
		q.pop();
		if(vis[p.d])continue;
		vis[p.d]=true;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&c[p.u][i]!=INF&&c[p.u][i]+dis[p.u]<dis[i]){
				dis[i]=c[p.u][i]+dis[p.u];
				q.push((Node){dis[i],i});
			}
		}
	}
	for(int i=1;i<=n;i++)ans+=dis[i];
}

inline void reverse(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			swap(c[i][j],c[j][i]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=INF;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		c[u][v]=min(c[u][v],w);
		c[i][i]=0;
	}
	Dijsktra();
	reverse();
	Dijsktra();
	printf("%d",ans);
	return 0;
} 
