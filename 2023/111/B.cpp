#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T,n,x[100009],t[100009],m;
const double res=1e-7;
double ans;

int check(double k){
	double lm=0,rm=0;
	for(int i=0;i<n;i++){
		if(x[i]<k)
			lm=max(lm,fabs(x[i]-k)+t[i]);
		else if(x[i]>k)
			rm=max(rm,fabs(x[i]-k)+t[i]);
	}
	return rm>=lm;
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
			m=max(m,x[i]);
		}
		for(int i=0;i<n;i++)
			scanf("%d",&t[i]);
			
		double l=0,r=m*1.0;
		while(r-l<res){
			double mid=l+(r-l)/2.0;
			if(check(mid)) l=mid;
			else r=mid;
			ans=mid;
		}
		ans*=10.0;
		ans=round(ans);
		ans/=10.0;
		if(ceil(ans)==floor(ans))
			printf("%d\n",(int)ans);
		else
			printf("%.1lf\n",ans);
	}
	return 0;
}
