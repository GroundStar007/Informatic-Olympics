#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int k,n,m,a,b,cow[1009];
vector<int>pas[1009];
int ans;

void dfs(int now,int ori){
	if(pas[now].empty)return;
	if(!cow[now])
}

int main(){
// 	freopen("1.txt","r",stdin);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		cow[a]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		pas[b].push_back(a); // ���򽨱�
	}
	for(int i=1;i<=n;i++)dfs(i,i);
	return 0;
}
