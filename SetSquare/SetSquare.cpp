#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>

std::string s;
char x='x';
int a,b,c;  // 各项系数
int lenth;  // 多项式长度
int num[20];  // 储存各分块起点和终点
bool PoNa[3];  // 标记系数正负性
int frac[3];  // 标记系数是否为分数和分母

int gcd(int x,int y){  // 最大公约数
    return y==0?x:gcd(y,x%y);
}

int STOI(std::string f){  // string转数字
    int p;
    const char *str = f.c_str();
    sscanf(str,"%d",&p);
    return p;
}

int CheckUpFactor(int i){
    int h=0,t=0,k,l,r;
    std::string factor="";
    int fac;

    if(s[num[i]-1]!=')'){
        for(k=num[i]-1;k>=num[i-1];k--)
            if(!(s[k]>='0' && s[k]<='9')){
                if(s[k]=='-')
                    PoNa[i-1]=true;
                break;
            }
        factor=s.substr(k+1,num[i]);
        fac=STOI(factor);
        // std::cout<<"非分母系数 "<<fac<<std::endl;
        return fac;
    }

    else if(s[num[i]-1]==')'){
        int denominator;  // 分母
        int numerator;    // 分子
        int common;       // 公因数
        k=r=num[i]-1;
        while(s[k]!='/')k--;
        l=k;
        while(s[l]!='(')l--;

        if(l>0 && s[l-1]=='-')
            PoNa[i-1]=true;

        // 找分子
        factor=s.substr(l+1,k);
        numerator=STOI(factor);

        // 找分母
        factor=s.substr(k+1,r);
        denominator=STOI(factor);

        // 找公因数 + 分数约分
        common=gcd(numerator,denominator);
        numerator/=common,denominator/=common;
        frac[i-1]=denominator;
        // printf("分母系数 %d %d\n",numerator,denominator);

        return numerator;
    }
    return 0;
}

void PrintFraction(int nume,int deno){
    if(deno==1)
        if(nume>0)printf("+%d",nume);
        if(nume<0)printf("%d",nume);
    if(deno!=1)
        if(nume>0 && deno>0)
            printf("+(%d/%d)",nume,deno);
        else if(nume<0 && deno<0)
            printf("+(%d/%d)",abs(nume),abs(deno));
        else if(nume<0 || deno<0)
            printf("-(%d/%d)",abs(nume),abs(deno));
}

int main(){
    freopen("1.txt","r",stdin);
    std::cin>>s;
    lenth=s.size();
    frac[0]=frac[1]=frac[2]=1;

    // 分块
    int t=1;  // 标记找到哪一块
    for(int i=0;i<lenth;i++)
        if(s[i]==x)
            num[t++]=i;
    num[t]=lenth;

    // 找 a,b,c
    a=b=c=INT_MAX;
    t=0;
    for(int i=1;i<=3;i++){
        int m=CheckUpFactor(i);
        if(i==1)a=m;
        if(i==2)b=m;
        if(i==3)c=m;
    }
    if(!a)a=1;  // 判定省略系数1
    if(!b)b=1;
    if(PoNa[0]==true)a*=-1;
    if(PoNa[1]==true)b*=-1;
    if(PoNa[2]==true)c*=-1;

    // 消除分数影响
    int l1=frac[0],l2=frac[1],l3=frac[2];
    int l=((l1*l2/gcd(l1,l2))*l3)/gcd(l1*l2/gcd(l1,l2),l3);
    a*=(l/frac[0]);
    b*=(l/frac[1]);
    c*=(l/frac[2]);

    // 配方
    // 通过顶点公式，还需加上分数约分
    int Xtop,Xbottom,  // 顶点横坐标
        Ytop,Ybottom,  // 顶点纵坐标
        Xg,Yg,         // 分数公因子
        Ag;       // a 与公倍数通分
    Xtop=b,Xbottom=a*2;
    Ytop=4*a*c-(b*b),Ybottom=4*a*l;
    Xg=gcd(Xtop,Xbottom),Yg=gcd(Ytop,Ybottom),Ag=gcd(a,l);  // 找gcd
    if(Xg)Xtop/=Xg,Xbottom/=Xg;     // 横坐标通分
    if(Yg)Ytop/=Yg,Ybottom/=Yg;     // 纵坐标通分
    if(a<0)Xtop*=-1;
    a/=Ag,l/=Ag;    // a 通分

    // 输出
    if(l==1){
        if(a<0){  // 负数提前处理
            printf("-");
            a*=-1;
        }
        if(a!=1)printf("%d",a);  // 系数为1省略
    }
    if(l!=1)
        if(a>0 && l>0)
            printf("(%d/%d)",a,l);
        else if(a<0 && l<0)
            printf("(%d/%d)",abs(a),abs(l));
        else if(a<0 || l<0)
            printf("-(%d/%d)",abs(a),abs(l));
    printf("(x");
    PrintFraction(Xtop,Xbottom);
    printf(")^2");
    PrintFraction(Ytop,Ybottom);
    return 0;
}
