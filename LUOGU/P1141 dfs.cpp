#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

queue<int>px,py;
const int T=1009;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m,maze[T][T],sx,sy,ans=1,vis[T][T];
int g[T][T];
char ch;

inline void set(){
	int a=px.size();
	while(!px.empty()&&!py.empty()){
		g[px.front()][py.front()]=a;
		px.pop(),py.pop();
	}
}

inline void dfs(int x,int y,int now){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>n)continue;
		if(maze[xx][yy]==now||vis[xx][yy])continue;
		vis[xx][yy]=1;
		px.push(xx),py.push(yy);
		dfs(xx,yy,maze[xx][yy]);
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		cin>>ch;
    		maze[i][j]=(int)ch-48;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			dfs(1,1,maze[1][1]);
			set();
		}
	for(int i=0;i<m;i++){
		scanf("%d%d",&sx,&sy);
		printf("%d\n",g[sx][sy]);
	}
    return 0;
}




// 真得会谢  数据下下来对了,测得不对   ?????????

