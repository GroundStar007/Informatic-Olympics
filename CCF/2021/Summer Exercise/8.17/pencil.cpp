#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,minn=2e8,num,price,need1=0,need2=0;
    cin>>n;
    for(int i=0;i<3;i++)
    {
        need2=need1=0;
        cin>>num>>price;
        while(need1<n)
        {
            need2+=price;
            need1+=num;
        }
        if(need2<minn)minn=need2;
    }
    cout<<minn;
}