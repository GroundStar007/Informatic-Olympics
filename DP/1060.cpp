#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,v[30009],w[30009],f[30009],p;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&v[i],&p);
		w[i]=p*v[i];
	}
	for(int i=1;i<=m;i++)
		for(int j=n;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	printf("%d",f[n]);
	return 0;
}
