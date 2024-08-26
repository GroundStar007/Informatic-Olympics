#include <iostream>
#include <cstdio>
using namespace std;
int n,m,f[100009],z,x,y;
char h;
int find(int k){
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)f[x]=y;
}
bool check(int x,int y){
	return find(x)==find(y);
}
int main(){
//	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)merge(x,y);
		if(z==2)
			if(check(x,y))printf("Y\n");
			else printf("N\n");
	}
	return 0;
}
