#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, stone[109], f[109][109];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &stone[i]);
	memset(f, 0x3f, sizeof f);
	for (int len = 1; len <= n; len++)
		for (int i = 1; i <= 2 * n - 1; i++) 
		{
			int j = len + i - 1;
			for (int k = i; k < j && k <= 2 * n - 1; k++)
				f[i][j] = min(f[i][j], 
						f[i][k] + f[k + 1][j] + stone[j] - stone[i - 1]);
		}
	printf("%d\n", f[1][n]);
	memset(f, -1, sizeof f);
	for (int len = 1; len <= n; len++)
		for (int i = 1; i <= 2 * n - 1; i++) 
		{
			int j = len + i - 1;
			for (int k = i; k < j && k <= 2 * n - 1; k++)
				f[i][j] = max(f[i][j], 
						f[i][k] + f[k + 1][j] + stone[j] - stone[i - 1]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}
