#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char a;
    int num=0;
    for(int i=0;i<8;i++){
        cin>>a;
        if(a=='1')num++;
    }
    cout<<num;
    return 0;
}