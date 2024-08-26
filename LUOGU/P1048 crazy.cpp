#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=1e4+5,M=1e7+5;
long long t,m,ti[N],pr[N],f[M];

int main(){
     freopen("1.txt","r",stdin);
    scanf("%lld%lld",&t,&m);
    for(int i=1;i<=m;i++)scanf("%lld%lld",&ti[i],&pr[i]);
    for(int i=1;i<=m;i++)
        for(int j=ti[i];j<=t;j++)
            f[j]=max(f[j],f[j-ti[i]]+pr[i]);
    printf("%lld",f[t]);
    return 0;
}
