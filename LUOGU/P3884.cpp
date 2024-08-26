#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(a,b) ((a)<(b)?(b):(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,t[109][109],x,y,u,v,b[10000009];
int MaxDeep=-1,MaxWidth=-1,maxn=-1;

int main(){
	memset(t,63,sizeof(t));
	scanf("%d",&n);
	for(int i=1;i<n;i++){	
		scanf("%d%d",&u,&v);
		t[u][v]=1;
		t[v][u]=2;
		t[i][i]=0;
	}
	for(int k=1;k<=n;k++)  // Floyed 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[i][j]=MIN(t[i][j],t[i][k]+t[k][j]);
	for(int i=2;i<=n;i++){
		MaxDeep=MAX(MaxDeep,t[1][i]); // 最大深度 
		b[t[1][i]]++;
		maxn=MAX(maxn,t[i][1]);  // 统计字节点到根的最大路径 
	}
	for(int i=1;i<=maxn;i++)MaxWidth=MAX(MaxWidth,b[i]);
	scanf("%d%d",&x,&y);
	cout<<MaxDeep+1<<endl  // 加上根节点 
		<<MaxWidth<<endl
		<<t[x][y];
	return 0;
}
