#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,hei[109],dp[109],u,d,k=0x7fffffff;
int up=1,down=1;

int MaxUp(int l,int r){  // 左侧最长上升子序列 
	int MaxLeft=0;
	dp[r]=1;
	for(int i=r-1;i>=l;i--){
		for(int j=i+1;j<=r;j++)
			if(hei[j]>hei[i])
				dp[i]=max(dp[i],dp[j]);
		dp[i]++;
		MaxLeft=max(MaxLeft,dp[i]);
	}
	return r-l+1-MaxLeft;
}

int MaxDown(int l,int r){  // 右侧最长下降子序列 
	int MaxRight=0; 
	dp[r]=1;
	for(int i=r-1;i>=l;i--){
		for(int j=i+1;j<=r;j++)
			if(hei[j]<hei[i])
				dp[i]=max(dp[i],dp[j]);
		dp[i]++;
		MaxRight=max(MaxRight,dp[i]);
	}
	return r-l+1-MaxRight;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>hei[i];
	for(int i=2;i<=n;i++){
		if(hei[i]>hei[i-1])up++;
		if(hei[i]<hei[i-1])down++;
	}
	if(up==n||down==n){  // 判单调递增或单调递减 
		cout<<"0";
		return 0;
	}
	for(int i=1;i<n;i++){
		u=MaxUp(1,i),d=MaxDown(i+1,n);
		k=min(k,d+u);
		memset(dp,0,sizeof(dp));
	}
	cout<<k;
	return 0;
}
