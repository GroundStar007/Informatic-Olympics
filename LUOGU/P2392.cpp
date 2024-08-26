#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int s[4],study[4][30],Left,Right,minn;
int ans;

void dfs(int w,int k){
	if(k>s[w]){
		minn=min(minn,max(Left,Right));
		return;
	}
	Left+=study[w][k];
	dfs(w,k+1);
	Left-=study[w][k];
	Right+=study[w][k];
	dfs(w,k+1);
	Right-=study[w][k];
}

int main(){
	freopen("1.txt","r",stdin);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	for(int i=0;i<4;i++){
		for(int j=0;j<s[i];j++)
			cin>>study[i][j];
		minn=0x7fffffff;
		Left=Right=0;
		dfs(i,0);
		ans+=minn;
	}
	printf("%d",ans);
	return 0;
}
