#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Queue{
	int x[1009],y[1009],head=0,tail=0;
	void push(int m,int n){x[tail]=m,y[tail]=n;tail++;}
	void pop(){if(head<tail)head++;}
	int empty(){return head>=tail?1:0;}
	int he(){return head;}
}z;
int n,num[40][40],vis[40][40];

inline void FindZero(){
	for(int i=0;i<n;i++){
		if(!num[0][i])z.push(0,i),vis[0][i]=1;
		if(!num[n-1][i])z.push(n-1,i),vis[n-1][i]=1;
		if(!num[i][0])z.push(i,0),vis[i][0]=1;
		if(!num[i][n-1])z.push(i,n-1),vis[i][n-1]=1;
	}	
	while(!z.empty()){
		int h=z.he();
		int x=z.x[h],y=z.y[h];
		z.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=n-1||yy<0||yy>=n-1)continue;
			if(!vis[xx][yy]&&!num[xx][yy])
				vis[xx][yy]=1,z.push(xx,yy);
		}
	}
}

inline void Print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(!vis[i][j])printf("2 ");
			else printf("%d ",num[i][j]);
		printf("\n");
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++){
    		scanf("%d",&num[i][j]);
    		vis[i][j]=num[i][j];
		}
    		
    FindZero();
    Print();
    return 0;
}

