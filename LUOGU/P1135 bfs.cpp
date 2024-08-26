#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct FLOOR{int num,t;}k[209];
int n,a,b,now,tn,h,vis[209];
queue<FLOOR>e;

int main(){
    freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d",&k[i].num);
    if(a==b){
        printf("0");
        return 0;
    }
    e.push((FLOOR){a,0});

    while(!e.empty()){
        now=e.front().num;
        tn=e.front().t;
        e.pop();
        if(now==b)break;
        if(now+k[now].num<=n&&!vis[now+k[now].num]){
            e.push((FLOOR){now+k[now].num,tn+1});
            vis[now+k[now].num]=1;
        }
        if(now-k[now].num>=1&&!vis[now-k[now].num]){
            e.push((FLOOR){now-k[now].num,tn+1});
            vis[now-k[now].num]=1;
        }
    }

    if(now==b)printf("%d",tn);
    else printf("-1");
    return 0;
}
