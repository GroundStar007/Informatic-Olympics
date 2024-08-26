#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

long long n,a,b,c,d,e;
char op[20],ad[30],h[30];
map<string,int>m;

int CheckAddress(){
    int t=sscanf(ad,"%lld.%lld.%lld.%lld:%lld",&a,&b,&c,&d,&e);
    if(t!=5)return 0;
    if(a<0||a>255)return 0;
    if(b<0||b>255)return 0;
    if(c<0||c>255)return 0;
    if(d<0||d>255)return 0;
    if(e<0||e>65335)return 0;
    sprintf(h,"%lld.%lld.%lld.%lld:%lld",a,b,c,d,e);
    if(strlen(h)!=strlen(ad))return 0;
    for(int i=0;i<strlen(ad);i++)
        if(h[i]!=ad[i])
            return 0;
    return 1;
}

int main(){
    scanf("%lld\n",&n);

    for(int i=1;i<=n;i++){
        scanf("%s %s",op,ad);
        string s(ad);
        if(!CheckAddress()){
            printf("ERR\n");
            continue;
        }
        if(op=="Server"){  // fuwuji
            if(m.count(s)!=0)
                printf("FAIL\n");
            else{
                printf("OK\n");
                m[s]=i;
            }
        }
        if(op=="Client"){  // kehuji
            if(m.count(s)==0)
                printf("FAIL\n");
            else
                printf("%d\n",m[s]);
        }
    }
    return 0;
}


// P7911 [CSP-J 2021] 网络连接
