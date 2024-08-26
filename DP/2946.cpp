#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
const int mod=100000000;
long long N, F, r[2009], f[10005][10005], ans;
int main()
{
	scanf("%lld%lld", &N, &F);
	for(int i = 1; i <= N; i ++)
	{
		scanf("%lld", &r[i]);
		r[i] %= F;
	}
	for(int i = 1; i <= N; i ++) f[i][r[i]] = 1;
	for(int i = 1; i <= N; i ++)
		{
		for(int j = 0; j < F; j ++)
			f[i][j] = ((f[i][j] + f[i - 1][j]) % mod + 
						f[i - 1][(j - r[i] + F) % F]) % mod;
		}
	printf("%d", f[N][0]);
	return 0;
}
