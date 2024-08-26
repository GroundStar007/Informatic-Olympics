#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 200
#define INF 1e9
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;

int n,x[MAXN],y[MAXN]; // 记录牧区的x,y坐标 
int f[MAXN],a;  // f[]记录不同牧区所处连通块 
double MaxSp[MAXN],  // MaxSp[i]记录每个连通块内i到其它点 最短路的最大值 
	m[MAXN][MAXN];  //  m[][]记录两点之间距离 
double MinDis=INF,  //  最后记录使 
	MaxDis,
	d[MAXN];  // 每个连通块的直径 (最短路的最大值

inline void dfs(int i,int id){  // dfs求连通块 
	f[i]=id;
	for(int j=1;j<=n;j++)	
		if(m[i][j]<INF*1.0&&!f[j])
			dfs(j,id);
}

inline double Distance(int k,int h){  // 欧几里得距离 
	return sqrt((x[k]-x[h])*(x[k]-x[h])+(y[k]-y[h])*(y[k]-y[h]))*1.0;
}

int main(){
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%1d",&a);
			if(a==1||i==j)m[i][j]=Distance(i,j);
			else m[i][j]=INF*1.0;
		}

	int id=1;
	for(int i=1;i<=n;i++)
		if(!f[i])dfs(i,id++);// dfs染色连通块

	for(int k=1;k<=n;k++)// Floyd
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
	
	for(int i=1;i<=n;i++)// 计算每个牧场中，每个牧区点到其他点的 最短路 的最大值。
		for(int j=1;j<=n;j++){//计算每个牧场中，所有最短路的最大值，即每个牧场的直径。
			if(m[i][j]<INF*1.0)
				MaxSp[i]=max(MaxSp[i],m[i][j]);
			d[f[i]]=max(d[f[i]],MaxSp[i]);
		} 

	for(int i=1;i<=n;i++)	// 找答案
		for(int j=1;j<=n;j++)
			if(f[i]!=f[j]){
				// 牧场 A 的所有最短路的最大值，牧场 B 的所有最短路的最大值，加边后通过这条边的最短路的最大值 
				// 三个取最大 
				MaxDis=max(max(d[f[i]],d[f[j]]),MaxSp[i]+Distance(i,j)+MaxSp[j]);
				MinDis=min(MinDis,MaxDis);
			}
	printf("%.6lf",MinDis);
	return 0;
}
