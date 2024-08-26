#include <iostream>
#include <algorithm>
using namespace std;
int n1[10009];
int main()
{
    int n,ans=0;
    bool flag=false;
    cin>>n;
    for(int i=0;i<n;i++)cin>>n1[i];
    sort(n1,n1+n,greater<int>());
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            for(int h=i+1;h<n;h++)
            {
                if(h==j)continue;
                if(n1[h]+n1[j]==n1[i])
                {
                    ans++;
                    flag=true;
                    break;
                }
            }
            if(flag==true)
            {
                flag=false;
                break;
            }
        }
    cout<<ans;
    return 0;
}