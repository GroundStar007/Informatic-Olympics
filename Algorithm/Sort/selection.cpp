#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    int n,n1[10009],minn;
    cin>>n;
    for(int i=0;i<n;i++)cin>>n1[i];
    for(int i=0;i<n;i++)
    {
        minn=i;
        for(int j=i+1;j<n;j++)
            minn=n1[j]<n1[minn]?j:minn;
        swap(n1[i],n1[minn]);
    }
    for(int i=0;i<n;i++)cout<<n1[i]<<" ";
    return 0;
}

//选择排序  O(n^2)  最没用但最简单   一般不要用