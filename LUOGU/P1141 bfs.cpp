#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Queue{
	int r[1000009],t[1000009],head=0,tail=0;
	void push(int x,int y){r[tail]=x,t[tail++]=y;}
	void pop(){if(head<tail)head++;}
	int empty(){return head>=tail?1:0;}
	int front(){return head;}
	int ta(){return tail;}
	void re(){head=tail=0;}
}q;
const int T=1009;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m,maze[T][T],sx,sy,ans=1,vis[T][T];
int g[T][T];
char ch;

inline void bfs(){
	while(!q.empty()){
		int h=q.front();
		int x=q.r[h],y=q.t[h];
		int l=maze[x][y];
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>n)continue;
			if(vis[xx][yy]||maze[xx][yy]==l)continue;
			vis[xx][yy]=1,ans++;
			q.push(xx,yy);
		}
	}
	for(int i=0;i<q.ta();i++)
		g[q.r[i]][q.t[i]]=ans;
	printf("%d\n",ans);
	ans=1;
	q.re();
}

int main(){
//    freopen("1.txt","r",stdin);
	memset(g,-1,sizeof(g));
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		cin>>ch;
    		maze[i][j]=(int)ch-48;
		}
	for(int i=0;i<m;i++){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&sx,&sy);
		if(g[sx][sy]!=-1){
			printf("%d\n",g[sx][sy]);
			continue;
		}
		vis[sx][sy]=1,q.push(sx,sy);
		bfs();
	}
    return 0;
}

