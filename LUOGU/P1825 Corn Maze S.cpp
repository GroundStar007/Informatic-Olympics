#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Path{int mx,ny,t;}h;
queue<Path>q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char ma[309][309];
int n,m,a,b,vis[309][309],sx,sy,nx,ny;

inline void find(char k,int &x,int &y){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(ma[i][j]==k&&(i!=x||j!=y)){
				x=i,y=j;
				return;
			}
}

int main(){
    freopen("1.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
    	cin.getline(ma[i],m+1);
    	for(int j=0;j<m;j++){
    		if(ma[i][j]=='@')sx=i,sy=j;
    		if(ma[i][j]=='=')nx=i,ny=j;
		}
	}
    q.push((Path){sx,sy,0});
    vis[sx][sy]=1;

    while(!q.empty()){
    	h=q.front();q.pop();
    	if(h.mx==nx&&h.ny==ny){
    		printf("%d",h.t);
    		return 0;
		}
		if(ma[h.mx][h.ny]>='A'&&ma[h.mx][h.ny]<='Z')
			find(ma[h.mx][h.ny],h.mx,h.ny);

		for(int i=0;i<4;i++){
			int xx=h.mx+dx[i],yy=h.ny+dy[i];
			if(xx<0||xx>=n||yy<0||yy>=m)continue;
			if(vis[xx][yy]||ma[xx][yy]=='#')continue;
			vis[xx][yy]=1;
			q.push((Path){xx,yy,h.t+1});
		}
	}
    return 0;
}
