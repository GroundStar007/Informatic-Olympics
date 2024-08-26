#include<bits/stdc++.h>
#define Ll long long
using namespace std;
int k,n,m,p,x,y,f[800][1600];
char c[800][1600];

//在第x,y点,a,b是用来判节点的,k表示点还是边，xx,yy表示这个点或这个边的父亲 
void dfs1(int x,int y,int a,int b,int k,int xx,int yy){
    if(x==n){
		c[x][y]='o';
		return;
	}
    if(k==1){
        c[x][y]='o';
        int X=xx+1,Y=(yy-1)*2+1;//左儿子 
        if(!f[X][Y])dfs1(x+1,y-1,a+1,b,2,X,Y);
        X=xx+1,Y=yy*2;//右儿子 
        if(!f[X][Y])dfs1(x+1,y+1,a+1,b,3,X,Y);
    }
	else if(k==2){
        c[x][y]='/';
        if(a*2==b)dfs1(x+1,y-1,1,a,1,xx,yy);//这个就是判断接下来是边还是点 
        else dfs1(x+1,y-1,a+1,b,2,xx,yy);
    }
	else if(k==3){
        c[x][y]=92;
        if(a*2==b)dfs1(x+1,y+1,1,a,1,xx,yy);
        else dfs1(x+1,y+1,a+1,b,3,xx,yy);
    }
}

void make(int k){
    n=3;
    for(int i=3;i<=k;i++)n*=2;
    m=6*(1<<(k-2))-1;//计算画布大小 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
			c[i][j]=' ';//填充画布 
    dfs1(1,m/2+1,1,n,1,1,1);    
}

int main(){
    scanf("%d%d",&k,&p);
    while(p--){
		scanf("%d%d",&x,&y);
		f[x][y]=1;//记录这个节点是否可以画
	} 
    if(k==1)n=m=1,c[1][1]='o';
	else make(k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
			cout<<c[i][j];
		cout<<endl;
    }
}
