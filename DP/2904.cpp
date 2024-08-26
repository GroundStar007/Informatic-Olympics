#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int N,M,m,f[2509],summ[2509];
// f[i]为载i头奶牛所用最小时间 
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		f[i]=1e9;
		scanf("%d",&m);
		summ[i]=summ[i-1]+m;
	}
	for(int i=1;i<=N;i++)summ[i]+=2*M;
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)
			f[j]=min(f[j],f[j-i]+summ[i]);
	printf("%d",f[N]-M);
	return 0;
}
