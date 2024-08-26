#include <iostream>
#include <cstdio>
int main()
{
    int k,n,coin=0;
    scanf("%d",&k);               //输入总天数k
    for(n=1;k-n>=0;k-=n++)       //第1天骑士可获得1枚金币
        coin+=n*n;               //在接下来的连续n天里，骑士每天可获得n枚金币
    printf("%d\n",coin+k*n);   //输出骑士总共可获得的金币数
    return 0;
}