#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <cstdlib>
using namespace std;
typedef long long ll;

inline ll read(){
    ll w=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){w=w*10+c-'0';c=getchar();}
    return w*f;
}

const int N = 2e5 + 10;
ll n, X, Y;
struct Dish{
    ll sweet, salty;
}f[N];

inline bool cmp1(Dish a, Dish b) {
	return a.sweet < b.sweet;
}

inline bool cmp2(Dish a, Dish b) {
	return a.salty < b.salty;
}

int main() {
    n = read(), X = read(), Y = read();
    for (int i = 1; i <= n; i++)
		f[i].sweet = read();
	for (int i = 1; i <= n; i++)
		f[i].salty = read();
    sort(f + 1, f + n + 1, cmp1);
	ll S = 0, T = 0;
    int ans = 0x7fffffff, tmp = 0;
	for (int i = n; i >= 1; i--) {
		if (S <= X && T <= Y) {
			tmp++;
			S += f[i].sweet;
			T += f[i].salty;
		} else break;
	}
	ans = min(ans, tmp);
	S = 0, T = 0, tmp = 0;
	sort(f + 1, f + n + 1, cmp2);
	for (int i = n; i >= 1; i--) {
		if (S <= X && T <= Y) {
			tmp++;
			S += f[i].sweet;
			T += f[i].salty;
		} else break;
	}
	ans = min(ans, tmp);
	cout << ans << "\n";
    return 0;
}
