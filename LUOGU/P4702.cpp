#include <iostream>
#include <cstdio>
using namespace std;
int n,a,summ;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        summ+=(a%2);
    }
    if(summ%2)printf("Alice");
    else printf("Bob");
    return 0;
}
