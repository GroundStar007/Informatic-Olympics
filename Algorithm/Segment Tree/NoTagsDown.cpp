#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long

ll a[400009],c[400009],v[400009];  // a是原始数列  c是线段树
ll k,y,m,n,flag,x;

void buildtree(int x,int l,int r){  // 建树
    if(l==r){
        c[x]=a[l];
        return;
    }
    int mid=(l+r)/2;
    buildtree(x*2,l,mid);  // 左半边
    buildtree(x*2+1,mid+1,r);
    c[x]=c[x*2]+c[x*2+1];
}

ll calc(int x,int l,int r,int s,int t,ll p){  // 区间和（无标记下传
    p+=v[x];  // 累计从根节点至此的v值
    if(l==s&&r==t)
        return c[x]+p*(t-s+1);

    ll mid=(l+r)/2;
    if(t<=mid)  // 左
        return calc(x*2,l,mid,s,t,p);
    else if(s>mid)  // you
        return calc(x*2+1,mid+1,r,s,t,p);
    else
        return calc(x*2,l,mid,s,mid,p)+calc(x*2+1,mid+1,r,mid+1,t,p);
}

void add(int x,int l,int r,int s,int t,int k){  // 区间更新
    if(l==s&&r==t){
        v[x]+=k;
        return;
    }
    c[x]+=k*(t-s+1);

    ll mid=(l+r)/2;
    if(t<=mid)
        add(x*2,l,mid,s,t,k);
    else if(s>mid)
        add(x*2+1,mid+1,r,s,t,k);
    else
        add(x*2,l,mid,s,mid,k),add(x*2+1,mid+1,r,mid+1,t,k);
}

int main(){
    freopen("1.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    buildtree(1,1,n);  // 先输入数列再建树

    while(m--){
        cin>>flag;
        if(flag==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            add(1,1,n,x,y,k);
        }
        if(flag==2){
            scanf("%lld%lld",&x,&y);
            cout<<calc(1,1,n,x,y,0)<<endl;
        }
    }
    return 0;
}

// 标记永久化，大概以后学主席树还有可持久化线段树会用
// 可能不好想，也可以用标记下传，好想一些
