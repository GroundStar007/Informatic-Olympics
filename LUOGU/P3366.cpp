#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int n,m,x,y,z,cnt=1;
int edge[5009][5009],minn[5009];
//priority_queue<

void prim(){
	minn[1]=0;
	
}

int main(){
// 	freopen("1.txt","r",stdin);
	memset(edge,63,sizeof(edge));
	memset(minn,63,sizeof(minn));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		edge[i][i]=0;
		edge[x][y]=z;
		edge[y][x]=z;
	}
	prim();
	return 0;
}
