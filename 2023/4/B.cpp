#include <iostream>
#include <cstdio>
using namespace std;

const int N=1000009;
int n,m,t,a,b,f[N],num[N];
char w;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)
		f[x]=y,num[y]+=num[x];
}
bool check(int x,int y){
	return find(x)==find(y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i,num[i]=1;
	while(m--){
		scanf(" %c",&w);
		if(w=='C'){
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		if(w=='Q'){
			scanf("%d",&t);
			if(t==1){
				scanf("%d%d",&a,&b);
				if(check(a,b))printf("Yes\n");
				else printf("No\n");
			}
			else if(t==2){
				scanf("%d",&a);
				printf("%d\n",num[find(a)]);
			}
		}
	}
	return 0;
}
