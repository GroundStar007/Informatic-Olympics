#include<stdio.h>
const int maxn=10;
int num[maxn],n,sum;
 
void dfs(int x){
    if(sum>n) return;
    if(sum==n){
        for(int i=0;i<x;i++){
            if(i==x-1) printf("%d\n",num[i]);
            else printf("%d+",num[i]);
        }
        return ;
    }
    for(int i=1;i<n;i++){
        if(x!=0){
            if(i<num[x-1]) continue;
        }
        num[x]=i;
        sum+=i;
        dfs(x+1);
        sum-=i;
    }
    
}
 
int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}
