#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,s,u,v,w,t[1009][1009];
long long dis[1009],r;
bool vis[1009];

int main(){
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			t[i][j]=0x3f;
		t[i][i]=0;
	}
	while(m--){
		scanf("%lld%lld%lld",&u,&v,&w);
		t[u][v]=w;
	}
	vis[s]=1,dis[s]=0;
	for(int i=1;i<=n;i++){
		int r=-1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(r==-1||dis[j]<dis[r]))
				r=j;
		vis[r]=1;
		for(int j=1;j<=n;j++)
			if(t[r][j]<1e9&&!vis[j]&&dis[r]+t[r][j]<dis[j])
				dis[j]=dis[r]+t[r][j];
//			dis[j]=MIN(dis[j],dis[r]+t[r][j]);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]);
	return 0;
}
