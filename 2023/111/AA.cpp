#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double n,l,r;
bool f=false;
int main(){
//	freopen("1.txt","r",stdin);
	scanf("%lf",&n);
	l=-10000,r=10000;
	while(r-l>0.00000001){
		double mid=l+(r-l)/2;
		double m=mid*mid*mid;
		if(m>n) r=mid;
		if(m<n) l=mid;
		if(fabs(m-n)<0.00000001){
			printf("%.6lf",mid);
			f=true;
			break;
		}
	}
	if(f==false)
		printf("%.6lf",l+(r-l)/2);
	return 0;
}
