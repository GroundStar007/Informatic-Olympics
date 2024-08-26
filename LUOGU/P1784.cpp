#include <iostream>
#include <cstdio>
using namespace std;

const int T=10;
int num[T][T],nx,ny,k=9;
int block[T][T],col[T][T],row[T][T];
bool flag;

inline void Print(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++)
			printf("%d ",num[i][j]);
		printf("\n");
	}
	flag=true;
}

inline void search(int x,int y){

}

inline void dfs(int xx,int yy){
	if(flag||xx>9)return;
	if(yy>9)xx+=1,yy=1;
	if(num[xx][yy])dfs(xx,yy+1);
	search(xx,yy);
	if(xx==nx&&yy==ny){Print();return;}	
	for(int i=1;i<=9;i++){
		if(block[(x-1)/3*3+(y-1)/3+1][i])continue;
		if(row[x][i]||col[y][i])continue;
		num[x][y]=i;
		block[(x-1)/3*3+(y-1)/3+1][i]=1;
    	row[x][i]=col[y][i]=1;
		num[xx][yy]=0;
	block[(xx-1)/3*3+(yy-1)/3+1][i]=0;
	row[xx][i]=col[yy][i]=0;
	}
	
}

int main(){
    freopen("1.txt","r",stdin);
    for(int i=1;i<=9;i++)
    	for(int j=1;j<=9;j++){
    		scanf("%d",&num[i][j]);
    		int m=num[i][j];
    		if(num[i][j]){
    			block[(i-1)/3*3+(j-1)/3+1][m]=1;
    			row[i][m]=col[j][m]=1;
			}
		}
		
	for(int i=9;i>=1;i--){
		if(!num[k][i]){
			nx=k,ny=i;
			break;
		}
		if(i==1)i=10,k--;
	}
    dfs(1,1);
    return 0;
}

