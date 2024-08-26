#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int TurnLeft[]={3,0,1,2},TurnRight[]={1,2,3,0};
int GO[]={1,2,3};
int n,m,sx,sy,nx,ny,l,r[100][100],vis[100][100];
char ch;
struct Queue{
	int robot[3000][4],head=0,tail=0;
	void push(int x,int y,int f,int t){
		robot[tail][0]=x,robot[tail][1]=y;
		robot[tail][2]=f,robot[tail++][3]=t;
	}
	void pop(){if(head<tail)head++;}
	int empty(){return head>=tail?1:0;}
	int front(){return head;}
}q;

inline int CheckFaceTo(char c){
	if(c=='E')return 0;
	else if(c=='S')return 1;
	else if(c=='W')return 2;
	else if(c=='N')return 3;
}

inline void Prepare(){
	for(int i=0;i<=n;i++)r[i][0]=r[i][m]=1;// 不能到边界 
	for(int i=0;i<=m;i++)r[0][i]=r[n][i]=1;
	int k=CheckFaceTo(ch);
	for(int i=0;i<3;i++){
		int xx=sx+dx[k]*GO[i],yy=sy+dy[k]*GO[i];
		if(xx<0||xx>n||yy<0||yy>n||r[xx][yy])break;
		vis[xx][yy]=1;
		q.push(xx,yy,k,1);
	}
	q.push(sx,sy,TurnLeft[k],1);
	q.push(sx,sy,TurnRight[k],1);
	vis[sx][sy]=1;
} 

inline void bfs(){
	while(!q.empty()){
		int h=q.front();
		int x=q.robot[h][0],y=q.robot[h][1];
		int f=q.robot[h][2],t=q.robot[h][3];
		q.pop();
		if(x==nx&&y==ny){
			printf("%d",t);
			exit(0);
		}
		for(int i=0;i<3;i++){
			int xx=x+dx[f]*GO[i],yy=y+dy[f]*GO[i];
			if(xx<0||xx>n||yy<0||yy>n||r[xx][yy])break;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push(xx,yy,f,t+1);
		}
		q.push(x,y,TurnLeft[f],t+1);
		q.push(x,y,TurnRight[f],t+1);
	}
}

int main(){
//  freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);  
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&l);
			if(l){
				r[i][j]=1;
				r[i+1][j]=1;
				r[i+1][j+1]=1;
				r[i][j+1]=1;	
			}
		}	
	scanf("%d%d%d%d %c",&sx,&sy,&nx,&ny,&ch);
	Prepare();
	if(sx==nx&&sy==ny){
		printf("0");
		return 0;
	}
	bfs();
	printf("-1");
    return 0;
}

