#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const double eps=1e-8;
int t,n,m,cntpara,Parabola[500],dp[1<<18];
inline void calc(double &a,double &b,int x1,int y1,int x2,int y2){
	a=(y1*x2-y2*x1)/(x1*x2*(x1-x2));
    b=(y1-a*x1*x1)/x1;
}
inline bool check(double a,double b,double x,double y){
	double ac=a*x*x+b*x-y;
	return fabs(ac)<=eps;
}
inline void solve(){
	cin>>n>>m;
	double px[20]={0},py[20]={0};
	for(int i=0;i<n;i++)
		cin>>px[i]>>py[i];
    memset(Parabola,0,sizeof Parabola);
	cntpara=0;
	for(int i=0;i<n;i++){
		Parabola[cntpara]=(1<<i);
		cntpara++;
		for(int j=i+1,vis=0;j<n;j++){
			if((vis>>j)&1)continue;
			else{
				double a,b;
                if(px[i]==px[j])continue;
				calc(a,b,px[i],py[i],px[j],py[j]);
				if(a>=0)continue;
				Parabola[cntpara]=(1<<i);
				for(int k=j;k<n;k++){
					if(check(a,b,px[k],py[k])){
						vis|=(1<<k);
						Parabola[cntpara]|=(1<<k);
					}
				}
				cntpara++;
			}
		}
	}
    memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<cntpara;j++){
			dp[i|Parabola[j]]=min(dp[i|Parabola[j]],dp[i]+1);
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
}
int main(){
	freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)solve();
	for (int i = 1; i <= n; i++) {

	}
	return 0;
}
