#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int dp[16][16],n,k,a[16],summ[17];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][0]=summ[i]=summ[i-1]+a[i];
        dp[1][i]=a[i];
    }
    for(int i=2;i<=n;i++)
		for(int j=1;j<=min(k,i-1);j++)
			for(int l=j;l<=i-1;l++)
				dp[i][j]=max(dp[i][j],dp[l][j-1]*(summ[i]-summ[l]));
    printf("%d",dp[n][k]);
    return 0;
}
