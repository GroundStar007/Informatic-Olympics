#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll x,p,result=1,m;
    scanf("%lld%lld%lld",&x,&p,&m);
    while(p>0){
        if(p&1)result=result*x%m;
        p>>=1;//此处等价于p=p/2
        x=(x*x)%m;
    }
    printf("%lld",result);
    return 0;
}
