#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int T,m,v[1009],t[1009],f[1009],ans;
int main(){
	scanf("%d%d",&T,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&t[i],&v[i]);
	for(int i=1;i<=m;i++)
		for(int j=T;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+v[i]);
	cout<<f[T];
	return 0;
} 
