#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,num[109];
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)cin>>num[i];
    for(int i=n,j=0;i>=0;i--,j++)
    {
        if(i==n)  //首项
        {
            if(num[j]<0)
            {
                cout<<"-";
                num[j]*=-1;
            }
            if(abs(num[j])!=1)cout<<num[j]<<"x^"<<i;  
            else if(abs(num[j])==1)cout<<"x^"<<i;
        }
        else if(i!=n&&num[j]!=0)
        {
            if(num[j]>0)cout<<"+";
            else if(num[j]<0)cout<<"-";
            if(abs(num[j])!=1)cout<<abs(num[j]);
            else if(abs(num[j])==1&&i==0)cout<<1;
            if(i!=0)
            {
                if(i==1)cout<<"x";
                else cout<<"x^"<<i;
            }
        }
    }
    return 0;
}