#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
const int NN=1000009;
long long N,H,p[NN],c[NN],f[NN],minn=INT_MAX;
int main(){
//	freopen("p.txt","r",stdin);
	scanf("%d%d",&N,&H);
	for(int i=1;i<=N;i++)
		scanf("%d%d",&p[i],&c[i]);
	for(int i=1;i<=H+5000;i++)f[i]=INT_MAX;
	for(int i=1;i<=N;i++)
		for(int j=p[i];j<=H+5000;j++)
			f[j]=min(f[j],f[j-p[i]]+c[i]);
	for(int i=H;i<=H+5000;i++)minn=min(minn,f[i]);
	printf("%d",minn);
	return 0;
}
