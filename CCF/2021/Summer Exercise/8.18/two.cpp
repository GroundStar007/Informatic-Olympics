#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int l,r,a,num=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        a=i;
        while(a)
        {
            if(a%10==2)num++;
            a/=10;
        }
    }
    cout<<num;
    return 0;
}