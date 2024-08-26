#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

const int T=10;
struct LineZero{int w,r;}p[T];
int cb[T][T]={
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6}
};
int num[T][T],block[T][T],col[T][T],row[T][T],m;
ll summ=-1;

int cmp(LineZero a,LineZero b){return a.w<b.w;}

inline void dfs(int x,int y,ll score,int n){
	if(n==10){summ=max(summ,score);return;}
	if(y>9){dfs(p[n+1].r,1,score,n+1);return;}

	if(!num[x][y]){
		int h=(x-1)/3*3+(y-1)/3+1;
		for(int i=1;i<=9;i++){
			if(block[h][i]||row[x][i]||col[y][i])continue;
			num[x][y]=i;
			block[h][i]=row[x][i]=col[y][i]=1;
			dfs(x,y+1,score+(num[x][y]*cb[x][y]),n);
			num[x][y]=0;
			block[h][i]=row[x][i]=col[y][i]=0;
		}
	}	
	else dfs(x,y+1,score+(num[x][y]*cb[x][y]),n);
}

int main(){
    // freopen("1.txt","r",stdin);
    for(int i=1;i<=9;i++)p[i].r=i;
    for(int i=1;i<=9;i++)
    	for(int j=1;j<=9;j++){
    		scanf("%d",&m);
    		if(!m)p[i].w++;
    		else{
    			block[(i-1)/3*3+(j-1)/3+1][m]=1;
    			row[i][m]=col[j][m]=1;
			}
			num[i][j]=m;
		}
	sort(p+1,p+10,cmp);
    dfs(p[1].r,1,0,1);
    printf("%lld",summ);
    return 0;
}

