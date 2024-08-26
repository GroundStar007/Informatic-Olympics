#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct metor{int nx,ny,t;}h;
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int m,x,y,t,xx,yy,farm[309][309],ans=0x3f;
queue<metor>q;

int main(){
    freopen("1.txt","r",stdin);
    memset(farm,0x3f,sizeof(farm));
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&t);
        for(int i=0;i<=4;i++){
            xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&yy>=0)  // 判出界
                farm[xx][yy]=min(farm[xx][yy],t);
        }
    }
    q.push((metor){0,0,1});

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<farm[i][j]<<" ";
        cout<<endl;
    }


    // while(!q.empty()){
    //     h=q.front();
    //     q.pop();
    //     if(farm[h.nx][h.ny]==0x3f){
    //         printf("%d",h.t);
    //         return 0;
    //     }
    //     for(int i=1;i<=4;i++){
    //         xx=h.nx+dx[i],yy=h.ny+dy[i];
    //         if(xx>=0&&yy>=0&&h.t+1<farm[xx][yy])
    //             q.push((metor){xx,yy,h.t+1});
    //     }
    // }
    // if(farm[h.nx][h.ny]==0x3f)printf("%d",h.t);
    printf("-1");
    return 0;
}
