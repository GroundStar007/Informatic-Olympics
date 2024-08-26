#include<iostream>
#include<cstdio>
using namespace std;
int father[150005],n;
int find(int k)
{
    if(father[k]!=k)
        father[k]=find(father[k]);
    return father[k];
}
void hebing(int a,int b)
{
    int A=find(a),B=find(b);
    father[A]=B;
    return;
}
int check(int c,int d)
{
    int C=find(c),D=find(d);
    if(C==D)return 1;
    if(find(c+n)==D)return 2;
    if(find(d+n)==C)return 3;
    return 0;
}
int main()
{
    int k,x,y,z,t,cnt;
    cin>>n>>k;
    for(int i=1;i<=3*n;i++)
        father[i]=i;
    cnt=0;
    for(int i=1;i<=k;i++)
    {
        cin>>z>>x>>y;
        if(x>n||y>n)
        {
            cnt++;
            continue;
        }
        t=check(x,y);
        if(t!=0&&t!=z)
        {
            cnt++;
            continue;
        }
        if(t==0)
        {
            if(z==1)
            {
                hebing(x,y);
                hebing(x+n,y+n);
                hebing(x+2*n,y+2*n);
            }
            else 
            {
                hebing(x+2*n,y+n);
                hebing(y+2*n,x);
                hebing(x+n,y);
            }
        }
    }
    cout<<cnt;
    return 0;
}
