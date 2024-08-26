#include <iostream>
#include <cstdio>
#define MAXN 0x7fff
using namespace std;
int h[MAXN],n,primes[MAXN],cnt;
int main(){
    cin>>n;
    h[0]=h[1]=1;
    for(int i=2;i<=n;i++){
        if(h[i]==0)primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            h[primes[j]*i]=1;
            if(i%primes[j]==0)break;
        }
    }
    for(int i=0;i<n;i++)
        if(!h[i])cout<<i<<" ";
    return 0;
}

//欧拉筛
