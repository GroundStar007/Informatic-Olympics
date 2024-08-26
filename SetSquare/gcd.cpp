#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

string s;
char x='x';
int a,b,c,t,place,lenth,num[20],n[20];

int gcd(int aa,int bb){  // 最大公约数
    int t;
    while(bb!=0){
        t=aa%bb;
        aa=bb;
        bb=t;
    }
    return aa;
}

int main(){
    cin>>a>>b>>c;
    int l=gcd((a*b)/gcd(a,b),(b*c)/gcd(b,c));
    printf("%d",gcd(a,b));
    printf("%d",gcd(b,c));
    printf("%d",l);
    if((-14)/10<0)cout<<"!!!!!!";
}

// gcd(a,gcd(b,c))<<" "<<(a*b/gcd(a,b))*c/gcd(a*b/gcd(a,b),c)
