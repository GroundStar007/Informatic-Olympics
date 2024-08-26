#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N=209;
int n,s[N],st[N],maxn[N][N],minn[N][N];
int maxl,minl=0x3f;

int main(){
	cin>>n;
	for(int i=1;i<=n+n;i++){
		cin>>s[i];
		s[i+n]=s[i];
		st[i]=st[i-1]+s[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			minn[i][j]=0x3f;
	for(int p=1;p<n;p++)
		for(int i=1,j=i+p;i<n+n&&j<n+n;i++,j=i+p)
			for(int k=i;k<j;k++){
				maxn[i][j]=max(maxn[i][j],maxn[i][k]+maxn[k+1][j]+st[j]-st[i-1]);
				minn[i][j]=min(minn[i][j],minn[i][k]+minn[k+1][j]+st[j]-st[i-1]);
			}
	for(int i=1;i<=n;i++){
		maxl=max(maxl,maxn[i][i+n-1]);
		minl=min(minl,minn[i][i+n-1]);
	}
	cout<<minl<<endl<<maxl;
	return 0;
} 
