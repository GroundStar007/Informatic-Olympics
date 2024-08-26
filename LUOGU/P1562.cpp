#include <iostream>
#include <cstdio>
using namespace std;
char ch;
int n,col[20],lr[40],rl[40],ans;
int c[20][20];

inline void dfs(int x){
	if(x>n){ans++;return;}
	for(int i=1;i<=n;i++){
		if(c[x][i]||col[i]||lr[i-x+n]||rl[i+x])
			continue;
		col[i]=lr[i-x+n]=rl[i+x]=1;
		dfs(x+1);
		col[i]=lr[i-x+n]=rl[i+x]=0;
	}
}

int main(){
    freopen("1.txt","r",stdin);
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		cin>>ch;
    		c[i][j]=(ch=='*'?0:1);
		}
    dfs(1);
    printf("%d",ans);
    return 0;
}


// t了俩点，要用位运算QAQ 
