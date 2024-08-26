#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}; 
int a[405][405],n,m,x,y;
bool vis[405][405];//visited�����ֹ�ظ�
int xx[8]={1,-1,2,-2,1,-1,2,-2},
	yy[8]={2,-2,1,-1,-2,2,-1,1};//��������
inline void bfs(int x,int y){
	a[x][y]=0;
	vis[x][y]=1;
	queue<node>q;
	q.push(node{x,y});//��ʼ������
	while(!q.empty()){
		node u=q.front();//ȡ����
		q.pop();
		for(register int i=0;i<8;i++){
			int dx=xx[i]+u.x;
			int dy=yy[i]+u.y;
			if(vis[dx][dy]) continue;
			if(dx<1||dx>n||dy<1||dy>m) continue;
			vis[dx][dy]=1;
			q.push(node{dx,dy});
			a[dx][dy]=a[u.x][u.y]+1;//ÿһ����һ
		}
	}
}
int main(){
	cin>>n>>m>>x>>y;
	memset(a,-1,sizeof a);
	memset(vis,0,sizeof vis);//��ʼ��
	bfs(x,y);//BFS��
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",a[i][j]);//���
		}
		printf("\n");
	}
	return 0;
}
