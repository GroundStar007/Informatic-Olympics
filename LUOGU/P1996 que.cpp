#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m,k=1;
queue<int>q;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty()){
        if(k==m){
            printf("%d ",q.front());
            q.pop();
            k=1;
            continue;
        }
        q.push(q.front());
        q.pop();
        k++;
    }
    return 0;
}
