#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,t[209],q,a,b,w,v[209][209];

inline void floyd(int k){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(v[i][j]>v[i][k]+v[k][j])
				v[i][j]=v[j][i]=v[i][k]+v[k][j];
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			v[i][j]=1e9;
		v[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&w);
		v[a][b]=v[b][a]=w;
	}
	scanf("%d",&q);
	while(q--){
		int x,y,t1,now=1;
		scanf("%d%d%d",&x,&y,&t1);
		if(t[x]>t1||t[y]>t1)cout<<"-1"<<endl;
		while(t[now]<=t1&&now<=n)floyd(now),now++;
		if(v[x][y]==1e9)cout<<"-1"<<endl;
		else cout<<v[x][y]<<endl;
	}
	return 0;
}
