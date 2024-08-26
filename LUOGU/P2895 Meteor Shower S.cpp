#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct metor{int nx,ny,t;}h;
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int m,x,y,t,xx,yy,farm[309][309],ans=0x3f;
int vis[309][309];
queue<metor>q;

int ch(int l){
	if(l==-1)return 9999999;
	else return l;
}

int main(){
    freopen("1.txt","r",stdin);
    memset(farm,-1,sizeof(farm));
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&t);
        for(int i=0;i<=4;i++){
            xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&yy>=0&&(farm[xx][yy]==-1||farm[xx][yy]>t))// ÅÐ³ö½ç
                farm[xx][yy]=t;
        }
    }
    vis[0][0]=1;
    q.push((metor){0,0,1});

	while(!q.empty()){
		h=q.front();
		q.pop();
		if(farm[h.nx][h.ny]==-1){
			printf("%d",h.t);
			return 0;
		}
		for(int i=1;i<=4;i++){
			xx=h.nx+dx[i],yy=h.ny+dy[i];
			if(xx>=0&&yy>=0&&h.t+1<ch(farm[xx][yy])&&!vis[xx][yy]){
				q.push((metor){xx,yy,h.t+1});
				vis[xx][yy]=1;
			}

		}
	}
//	if(farm[h.nx][h.ny]==-1)printf("%d",h.t);
    printf("-1");
    return 0;
}

