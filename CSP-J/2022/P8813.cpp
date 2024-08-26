#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long a,b,c=1;
long long e=1000000000;

int main(){
    scanf("%lld%lld",&a,&b);

    for(int i=1;i<=b;i++){
        if(e/c<a){
            cout<<"-1";
            return 0;
        }
        c*=a;
    }

    printf("%lld",c);
    return 0;
}
