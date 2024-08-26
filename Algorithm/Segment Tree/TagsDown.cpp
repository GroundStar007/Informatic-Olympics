#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
#define NUM 400009

ll s[NUM];          // 线段树
ll num[NUM];        // 原始数列
ll tagAdd[NUM];     // 加法标记
ll tagMulti[NUM];    // 乘法标记
ll n,m,x,y,k,p;

void buildtree(int k,int l,int r){
    tagMulti[k]=1;
    if(l==r){
        s[k]=num[l];
        return;
    }
    ll mid=(l+r)/2;
    buildtree(k*2,l,mid);
    buildtree(k*2+1,mid+1,r);
    s[k]=(s[k*2]+s[k*2+1])%p;
}

void push_down(int k,int l,int r){
    ll mid=(l+r)/2;

    // 左右儿子值改变
    s[k*2]=(s[k*2]*tagMulti[k]+(mid-l+1)*tagAdd[k])%p;
    s[k*2+1]=(s[k*2+1]*tagMulti[k]+(r-mid)*tagAdd[k])%p;

    // 标记下传
    tagMulti[k*2]=(tagMulti[k*2]*tagMulti[k])%p;
    tagMulti[k*2+1]=(tagMulti[k*2+1]*tagMulti[k])%p;
    tagAdd[k*2]=(tagAdd[k*2]*tagMulti[k]+tagAdd[k])%p;
    tagAdd[k*2+1]=(tagAdd[k*2+1]*tagMulti[k]+tagAdd[k])%p;

    // 清空标记
    tagMulti[k]=1;
    tagAdd[k]=0;
}

void multiply(int k,int l,int r,int x,int y,ll w){
    if(x==l&&r==y){
        tagMulti[k]=(tagMulti[k]*w)%p;
        tagAdd[k]=(tagAdd[k]*w)%p;
        s[k]=(s[k]*w)%p;
        return;
    }
    push_down(k,l,r);
    ll mid=(l+r)/2;
    if(y<=mid) multiply(k*2,l,mid,x,y,w);
    else if(x>mid) multiply(k*2+1,mid+1,r,x,y,w);
    else multiply(k*2,l,mid,x,mid,w),multiply(k*2+1,mid+1,r,mid+1,y,w);
    s[k]=(s[k*2]+s[k*2+1])%p;
}

void add(int k,int l,int r,int x,int y,ll w){
    if(x==l&&r==y){
        tagAdd[k]=(tagAdd[k]+w)%p;
        s[k]=((r-l+1)*w+s[k])%p;
        return;
    }
    push_down(k,l,r);
    ll mid=(l+r)/2;
    if(y<=mid) add(k*2,l,mid,x,y,w);
    else if(x>mid) add(k*2+1,mid+1,r,x,y,w);
    else add(k*2,l,mid,x,mid,w),add(k*2+1,mid+1,r,mid+1,y,w);
    s[k]=(s[k*2]+s[k*2+1])%p;
}

ll check(int k,int l,int r,int x,int y){
    if(x==l&&r==y) return s[k]%p;
    push_down(k,l,r);
    ll mid=(l+r)/2,res;
    if(y<=mid) res=check(k*2,l,mid,x,y)%p;
    else if(x>mid) res=check(k*2+1,mid+1,r,x,y)%p;
    else res=(check(k*2,l,mid,x,mid)+check(k*2+1,mid+1,r,mid+1,y))%p;
    s[k]=(s[k*2]+s[k*2+1])%p;
    return res;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    buildtree(1,1,n);

    while(m--){
        int flag;
        scanf("%d",&flag);
        if(flag==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            multiply(1,1,n,x,y,k);
        }
        else if(flag==2){
            scanf("%lld%lld%lld",&x,&y,&k);
            add(1,1,n,x,y,k);
        }
        else{
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",check(1,1,n,x,y));
        }
    }
}
