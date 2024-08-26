#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int mod=1000000007;
int t,summ;
char s[109];
long long dp[109][5000];

int main(){
//  freopen("1.txt","r",stdin);
	for(int i=0;i<26;i++)dp[1][i]=1;
	for(int i=2;i<=100;i++){
		dp[i][0]=1;
		for(int j=1;j<=2700;j++)
			for(int k=0;k<26;k++)
				if(j-k>=0)
					dp[i][j]=(dp[i][j]%mod+dp[i-1][j-k]%mod)%mod;
	}
	scanf("%d\n",&t);
	for(int i=0;i<t;i++){
		summ=0;
		cin>>s;
		for(int j=0;j<strlen(s);j++)summ+=s[j]-'a';
		printf("%lld\n",dp[strlen(s)][summ]%mod-1);
	}
    return 0;
}

