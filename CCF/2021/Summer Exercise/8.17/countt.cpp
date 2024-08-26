#include<iostream>
using namespace std;
int main()
{
    int n,x,ans=0,a;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        a=i;
        while(true)
        {
            if(a<=0)break;
            if(a%10==x)ans++;
            a/=10;
        }
    }
    cout<<ans;
    return 0;
}