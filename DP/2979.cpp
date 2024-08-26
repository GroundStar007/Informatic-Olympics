#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int N, T, K, v[1009], f[1009], h[1009], ans;
int main()
{
	scanf("%d%d%d", &N, &T, &K);
	for(int i = 1; i <= N; i ++) scanf("%d%d", &v[i], &h[i]);
	for(int i = 1; i <= N; i ++)
		for(int j = h[i]; j <= T*5/4; j ++)
			f[j] = max(f[j], f[j - h[i]] + v[i]);
	ans = f[T];
	for (int i = 1; i <= N; i ++)
    	if (h[i] >= K) 
			ans = max(ans, f[(T - h[i])*5/4] + v[i]);
	printf("%d\n", ans);
	return 0;
}
