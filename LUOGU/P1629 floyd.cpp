#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int min(int a,int b){return a<b?a:b;}

int n,m,u,v,w,c[1009][1009];
int ans;

int main(){
	memset(c,0x3f,sizeof(c));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		c[u][v]=min(c[u][v],w);
		c[i][i]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(c[i][j]>c[i][k]+c[k][j])
					c[i][j]=c[i][k]+c[k][j];
	for(int i=2;i<=n;i++)
		ans+=(c[1][i]+c[i][1]);
	printf("%d",ans);
	return 0;
}
