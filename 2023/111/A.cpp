#include <iostream>
#include <cstdio>
using namespace std;

int W,H,x,y,h[29][29],ans;
char a;
bool b[29][29];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int l,int c){
	if(l>H||l<1||c>W||c<1) return;
	if(h[l][c]==1||b[l][c]==true) return;
	b[l][c]=true;
	ans++;
	for(int i=0;i<=3;i++)
		dfs(l+dx[i],c+dy[i]);
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d %d\n",&W,&H);
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			scanf("%c",&a);
			if(a=='@') x=i,y=j,h[i][j]=2;
			else if(a=='#') h[i][j]=1;
			else h[i][j]=0;
		}
		scanf("\n");
	}
	dfs(x,y);
	cout<<ans;	
	return 0;
}
