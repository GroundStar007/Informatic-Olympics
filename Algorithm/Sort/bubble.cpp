#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    int n,n1[1000009];
    cin>>n;
    for(int i=0;i<n;i++)cin>>n1[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(n1[j]>n1[j+1])
                swap(n1[j],n1[j+1]);
    for(int i=0;i<n;i++)cout<<n1[i]<<" ";
    return 0;
}

//冒泡排序