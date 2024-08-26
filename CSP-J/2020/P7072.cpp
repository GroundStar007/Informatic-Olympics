#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,w,score,s[609],MaxScore=0;

int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++){
        scanf("%d",&score);
        s[score]++;
        if(MaxScore<score)MaxScore=score;
        int l=max(1,(int)floor(i*w/100));
        // printf("%d ",l);
        int num=0;
        for(int j=MaxScore;j>=1;j--){
            if(s[j])num+=s[j];
            if(num>=l){
                printf("%d ",j);
                break;
            }
        }
        if(!num||num<l)printf("0 ");
    }
    return 0;
}


/* [CSP-J2020] 直播获奖 */
