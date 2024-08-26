#include <bits/stdc++.h>
using namespace std;
bool IsLeapYear(int h)
{
    return (h%4==0&&h%100!=0)||h%400==0;
}
int NextMonthYear(int j)
{
    //一三五七八十腊，三十一天永不差
    if(j%10000/100==1&&j%100>31)j+=69;
    else if(j%10000/100==3&&j%100>31)j+=69;
    else if(j%10000/100==5&&j%100>31)j+=69;
    else if(j%10000/100==7&&j%100>31)j+=69;
    else if(j%10000/100==8&&j%100>31)j+=69;
    else if(j%10000/100==10&&j%100>31)j+=69;
    else if(j%10000/100==12&&j%100>31)j+=8869; //下一年
    //四六九冬三十天
    else if(j%10000/100==4&&j%100>30)j+=70;
    else if(j%10000/100==6&&j%100>30)j+=70;
    else if(j%10000/100==9&&j%100>30)j+=70;
    else if(j%10000/100==11&&j%100>30)j+=70;
    else if(j%10000/100==2)
    {
        //闰年二月二十九
        if(IsLeapYear(j/10000)==true&&j%100>29)j+=71;
        //平年二月二十八
        else if(IsLeapYear(j/10000)==false&&j%100>28)j+=72;
    }
    return j;
}
bool IsPalindromicNumber(int y)
{
    if(y%10!=y/10000000)return false;
    if(y%100/10!=y%10000000/1000000)return false;
    if(y%1000/100!=y%1000000/100000)return false;
    if(y%10000/1000!=y%100000/10000)return false;
    return true;
}
int main(){
    // freopen("8.17.txt","r",stdin);
    int start,end1,num,s4,e4,i;
    scanf("%d%d",&start,&end1);
    for(i=start;i<=end1;i++)
    {
        i=NextMonthYear(i);
        if(IsPalindromicNumber(i)==true)num++;
    }
    cout<<num;
    return 0;
}