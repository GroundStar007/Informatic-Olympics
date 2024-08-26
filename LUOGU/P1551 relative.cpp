#include <iostream>
#include <cstdio>
using namespace std;

int n,m,p,a,b;
int fa[5009];

int Find(int x){
	if(fa[x]=x)return fa[x];
	else return fa[x]=Find(fa[x]);
}

int main(){
	cin>>n>>m>>p;
	for(int i=0;i<5000;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		cin>>a>>b;

	}
	return 0;
}
