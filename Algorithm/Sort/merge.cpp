#include <bits/stdc++.h>
using namespace std;
int n,n1[10009];
void MergeSort(int leftPtr,int rightPtr,int rightBound)
{
    int i=leftPtr,j=rightPtr,k=0,mid=rightPtr-1;
    int temp[rightBound-rightPtr+1]={0};
    while(i<=mid&&j<=rightBound)
        temp[k++]=(n1[i]<=n1[j])?n1[i++]:n1[j++];
    while(i<=mid)temp[k++]=n1[i++];
    while(j<=rightBound)temp[k++]=n1[j++];
    for(int o=0;o<=rightBound-rightPtr+1;o++)
        n1[leftPtr+o]=temp[o];
}
void sort(int left,int right)
{
    int mid=left+(right-left)/2;//中间点
    if(left==right||right<0||left<0||right<left)return;
    sort(left,mid);//左半边
    sort(mid+1,right);//右半边
    MergeSort(left,mid+1,right);
}
int main()
{
    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)cin>>n1[i];
    sort(0,n-1);
    for(int i=0;i<n;i++)cout<<n1[i]<<" ";
    return 0;
}

//归并排序