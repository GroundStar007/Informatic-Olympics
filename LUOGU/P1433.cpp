#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,x[20],y[20],vis[20],j;
double ans=0x7fffffff,k;

void dfs(int h,int dis,int num){
	if(num==1){
		for(j=0;j<n&&vis[j];j++);
		k=dis+sqrt(pow((x[h]-x[j]),2.0)+pow((y[h]-y[j]),2.0));
		if(ans>k)ans=k;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]&&i!=h){
			vis[i]=1;
			dfs(i,dis+sqrt(pow((x[h]-x[i]),2.0)+pow((y[h]-y[i]),2.0)),num-1);
			vis[i]=0;
		}
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<n;i++){
		vis[i]=1;
		dfs(i,sqrt(x[i]*x[i]+y[i]*y[i]),n);
		vis[i]=0;
	}
	printf("%.2f",ans);
    return 0;
}

