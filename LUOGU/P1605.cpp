#include <iostream>
#include <cstdio>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,t,sx,sy,fx,fy,x,y;
int k[10][10],vis[10][10],ans;

void dfs(int xx,int yy){
	if(k[xx][yy]==-1)return;
	if(xx<1||xx>n||yy<1||yy>m)return;
	if(xx==fx&&yy==fy){
		ans++;
		return;
	} 
	for(int i=0;i<4;i++){
		int g=xx+dx[i],h=yy+dy[i];
		if(!vis[g][h]){
			vis[g][h]=1;
			dfs(g,h);
			vis[g][h]=0;
		}
	}
} 

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=1;i<=t;i++){
    	scanf("%d%d",&x,&y);
    	k[x][y]=-1;
	}
	vis[sx][sy]=1;	
	dfs(sx,sy);
	printf("%d",ans);
    return 0;
}

