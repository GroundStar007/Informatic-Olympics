#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,a[200],num[200];

inline int dfs(int st,int en){
	if(en-st>1){
		int ll=dfs(st,(st+en)/2);
		int rr=dfs((st+en)/2+1,en);
		return (a[ll]>a[rr])?ll:rr;
	}
	else{
		int ll=st,rr=en;
		return (a[ll]>a[rr])?ll:rr;
	}
}

int main(){
	freopen("1.txt","r",stdin);
	cin>>n;
	int t=pow(2,n*1.0);
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
		num[i]=i;
	}
	int m=dfs(1,t/2);
	int n=dfs(t/2+1,t);
	printf("%d",(a[m]>a[n])?n:m);
	return 0;
}
