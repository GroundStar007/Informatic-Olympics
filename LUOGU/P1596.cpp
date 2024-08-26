#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
int n,m,vis[109][109],ans;
char f[109][109];

inline void dfs(int x,int y){
	if(x<0||x>=n||y<0||y>=m||f[x][y]=='.')return;
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(!vis[xx][yy])dfs(xx,yy);
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++)
    	cin.getline(f[i],101);
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		if(f[i][j]=='W'&&!vis[i][j]){
    			ans++;
    			dfs(i,j);
			}
	printf("%d",ans);
    return 0;
}

