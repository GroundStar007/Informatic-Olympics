#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int>v[100009];
int n,q,t,a,b,k;

int main(){
    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&a,&b,&k);
            v[a][b]=k;
        }
        if(t==2){
            scanf("%d%d",&a,&b);
            printf("%d\n",v[a][b]);
        }
    }
    return 0;
}
