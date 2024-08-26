#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
const int N=1e5+100;

int t,tot,op;
ll Q,M,m,s[N<<2];

void change(int now,ll l,ll r,int z,ll k){
    if(l==r){
        s[now]=k%M;
        return;
    }
    ll mid=(l+r)>>1;
    if(z<=mid) change(now*2,l,mid,z,k);
    if(z>mid) change(now*2+1,mid+1,r,z,k);
    s[now]=((s[now*2]%M)*(s[now*2+1]%M))%M;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&Q,&M);
        for(int i=0;i<=(Q<<2);i++) s[i]=1;
        for(int i=1;i<=Q;i++){
            scanf("%d%lld",&op,&m);
            if(op==1) change(1,1,Q,i,m);
            if(op==2) change(1,1,Q,m,1);
            printf("%lld\n",s[1]%M);
        }
    }
}
