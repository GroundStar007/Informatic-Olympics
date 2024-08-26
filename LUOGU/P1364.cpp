#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Node{int m,h,ll,rr;}k[109];
int n,w,u,v,ans=0x7fffffff,vis[109];

inline int dfs(int p,int len){
	int t=k[p].m*len;
	vis[p]=1;
	if(k[p].h&&!vis[k[p].h])t+=dfs(k[p].h,len+1);
	if(k[p].ll&&!vis[k[p].ll])t+=dfs(k[p].ll,len+1);
	if(k[p].rr&&!vis[k[p].rr])t+=dfs(k[p].rr,len+1);
	return t;
}

int main(){
//  freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&w,&u,&v);
		k[i].m=w;
		k[u].h=k[v].h=i;
		k[i].ll=u;
		k[i].rr=v;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans=min(dfs(i,0),ans);
	}
	printf("%d",ans);
    return 0;
}

