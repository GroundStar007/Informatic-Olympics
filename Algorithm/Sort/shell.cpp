#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1.txt","r",stdin);
    int n,n1[10009],n2[10009],h;//h为Knuth序列的间隔
    cin>>n;
    for(int i=0;i<n;i++)//输入
    {
        cin>>n1[i];
        n2[i]=n1[i];
    }
    //第一种取间隔的思想  二分，每次取一半  gap为间隔
    for(int gap=n>>1;gap>0;gap>>=1)
        for(int i=gap;i<n;i++)//每次取得数往后一位，间隔不变
            for(int j=i;j>gap-1&&n1[j]<n1[j-gap];j-=gap)
                swap(n1[j],n1[j-gap]);

    //第二种  Knuth序列  h一开始为1/3数组长度+1 每次-1  效率更高
    h=1;//一开始h为1
    while(h<=n/3)//小于1/3数组长度
        h=h*3+1;

    for(int gap=h;gap>0;gap=(gap-1)/3)//根据上一个循环得出  一开始为h
        for(int i=gap;i<n;i++)
            for(int j=i;j>gap-1&&n2[j]<n2[j-gap];j-=gap)
                swap(n2[j],n2[j-gap]);

    for(int i=0;i<n;i++)cout<<n1[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<n2[i]<<" ";
    return 0;
}

//希尔排序  改进的 "插入排序" ，效率更佳
//在间隔大的时候，次数比较少，在长度大的时候，间隔小