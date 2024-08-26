#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;


int n,m,s[1009][1009];
long long ans=-1e18;
int dx[]={1,-1,0},dy[]={0,0,1};
bool f[1009][1009];

void dfs(int x,int y,long long cnt){
	if(x<1||x>n||y<1||y>m||f[x][y]==true)
		return;
	if(x==n&&y==m){
		ans=max(ans,cnt+s[n][m]);
		return;
	}
	f[x][y]=true;
	dfs(x+1,y,cnt+s[x][y]);
	dfs(x-1,y,cnt+s[x][y]);
	dfs(x,y+1,cnt+s[x][y]);
	f[x][y]=false;
}

int main(){
//	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	dfs(1,1,0);
	printf("%lld",ans);
	return 0;
}
