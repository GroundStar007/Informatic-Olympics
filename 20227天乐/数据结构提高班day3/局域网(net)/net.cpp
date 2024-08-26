#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,ans;
struct edge
{
	int u,v,w;
}e[N*N];
bool cmp(const edge& x,const edge& y)
{
	return x.w<y.w;	
} 

int fa[N];
int Find(int u)
{
	if(fa[u]==u)return u;
	return fa[u]=Find(fa[u]);
}
bool Merge(int u,int v)
{
	int fu=Find(u),fv=Find(v);
	if(fu==fv)return false;
	fa[fu]=fv;
	return true;
}
int main()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&w),e[i]=(edge){u,v,w},ans+=w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		if(Merge(e[i].u,e[i].v))ans-=e[i].w;
	printf("%d\n",ans);
	return 0;
}
