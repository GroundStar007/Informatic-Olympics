#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=100009;
int n,m,x,y,a,b,f[N],fr[N];
char c,col[N];

int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
		cin>>col[i];
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		if(col[x]==col[y])f[find(x)]=find(y);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d %c",&a,&b,&c);
		if(find(a)==find(b)&&c!=col[a])printf("0");
		else printf("1");
	}
	return 0;
}
