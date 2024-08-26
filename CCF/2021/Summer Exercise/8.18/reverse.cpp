#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long n,m=0;
    scanf("%lld",&n);
    while(n)
    {
        m=m*10+n%10;
        n/=10;
    }
    cout<<m;
    return 0;
}