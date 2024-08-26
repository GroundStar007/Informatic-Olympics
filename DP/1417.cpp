#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

struct Material{
	ll a, b, c;
}m[100001];
long long T, n, f[1000009], ans=LLONG_MIN;

bool cmp(Material x, Material y){
	return ((ll)x.b*(ll)y.c) < ((ll)y.b*(ll)x.c);
}

int main(){
	scanf("%lld%lld", &T, &n);
	memset(f, 255, sizeof(f));
	f[0]=0;
	for(int i=1; i<=n; i++) scanf("%lld", &m[i].a);
	for(int i=1; i<=n; i++) scanf("%lld", &m[i].b);
	for(int i=1; i<=n; i++) scanf("%lld", &m[i].c);
	sort(m+1, m+n+1, cmp);
	for(int i=1; i<=n; i++)
		for(int j=T; j>=0; j--)
			if(f[j] != -1 && j + m[i].c <= T)
				f[j + m[i].c] = max((ll)f[j + m[i].c], (ll)f[j] + ((ll)m[i].a - (ll)(j + m[i].c) * (ll)m[i].b));
	for(int i=1; i<=T; i++)ans = max(ans, f[i]);
	printf("%lld",ans);
	return 0;
}
