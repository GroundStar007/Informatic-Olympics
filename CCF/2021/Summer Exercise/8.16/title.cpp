#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char a[10];
    int num=0,len;
    cin.getline(a,6);
    len=strlen(a);
    for(int i=0;i<len;i++)
        if(a[i]!=' ')num++;
    cout<<num;
    return 0;
}