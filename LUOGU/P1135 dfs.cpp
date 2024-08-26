#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int minn(int m,int n){return m<n?m:n;}
int n,a,b,vis[209],k[209],ans=0x7fffffff;

void dfs(int x,int s){
    if(x==b)ans=minn(ans,s);
    if(s>ans)return;
    vis[x]=1;
    if(x+k[x]<=n&&!vis[x+k[x]])dfs(x+k[x],s+1);
    if(x-k[x]>=1&&!vis[x-k[x]])dfs(x-k[x],s+1);
    vis[x]=0;
}

int main(){
    freopen("1.txt","r",stdin);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>k[i];
    vis[a]=1;
    dfs(a,0);
    if(ans==0x7fffffff)cout<<"-1";
    else cout<<ans;
    return 0;
}
