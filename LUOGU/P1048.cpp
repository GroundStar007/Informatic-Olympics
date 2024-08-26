#include <iostream>
#include <cstdio>
using namespace std;
int max(int a,int b){return a>b?a:b;}

int t,m,w[1009],c[1009],dp[1009];

int main(){
 	freopen("1.txt","r",stdin);
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&w[i],&c[i]);
	
	for(int i=1;i<=m;i++)
		for(int j=t;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
	cout<<dp[t];
	return 0;
} 
