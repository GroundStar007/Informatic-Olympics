#include <iostream>
#include <cstdio>
using namespace std;

int n,a,b,maxb,s[1000009],ans,k;

int main(){
	// freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        s[a]++;
        s[b+1]--;
        maxb=maxb<b?b:maxb;
    }
    k=s[0];
    for(int i=1;i<=maxb;i++){
        k+=s[i];
        if(ans<k)ans=k;
    }
    printf("%d",ans);
    return 0;
}

// 差分 这样的话把修改的复杂度改到 O(n)
// 总共 O(n)  （ 考场上也没想出来
