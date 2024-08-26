#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N=409;
queue<int>xx,yy;
int x,y,m,n,chess[N][N],tx,ty;
bool vis[N][N];
int dx[8]={2,2,1,1,-2,-2,-1,-1};
int dy[8]={1,-1,-2,2,1,-1,2,-2};

int main(){
	freopen("1.txt","r",stdin);
	memset(chess,-1,sizeof(chess));
	cin>>n>>m>>x>>y;
	chess[x][y]=0,vis[x][y]=1;
	xx.push(x),yy.push(y);

	while(!xx.empty()&&!yy.empty()){
		for(int i=0;i<8;i++){
			tx=xx.front()+dx[i];
			ty=yy.front()+dy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]){
				vis[tx][ty]=1;
				xx.push(tx),yy.push(ty);
				chess[tx][ty]=chess[xx.front()][yy.front()]+1;
			}
		}
		xx.pop(),yy.pop();
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%-5d",chess[i][j]);
		cout<<endl;
	}
	return 0;
}
