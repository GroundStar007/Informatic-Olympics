#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath> 
using namespace std;
int n,s[15],b[15],minn=0x7fffffff;

void dfs(int x,int m,int k){
	if(x>n){ 
		if(m==1&&k==0)return; // 清水 
		minn=min(minn,abs(m-k));
		return;
	}
	dfs(x+1,m*s[x],k+b[x]);  // 选 
	dfs(x+1,m,k);  // 不选 
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
//    cout<<n;
    for(int i=1;i<=n;i++)
    	scanf("%d%d",&s[i],&b[i]);
    dfs(1,1,0);
    printf("%d",minn);
    return 0;
}

