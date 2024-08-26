#include <bits/stdc++.h>
using namespace std;
int n,n1[10000];
int main()
{
    freopen("1.txt","r",stdin);
    //输入
    cin>>n;
    for(int i=0;i<n;i++)cin>>n1[i];
    for(int i=0;i<n;i++)
        for(int j=i;j>0&&n1[j]<n1[j-1];j--)//每次与它前面的一位比较，若小就交换
            swap(n1[j],n1[j-1]);
    for(int i=0;i<n;i++)cout<<n1[i]<<" ";
    return 0;
}

//插入排序   最实用的简单排序