#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, stone[40009], s, f[1009][1009];
int main()
{
	scanf("%d", &n);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i ++) 
	{
		scanf("%d", &s);
		stone[i] = stone[i - 1] + s;
		f[i][i] = 0;
	}
	
	for (int lenth = 2; lenth <= n; lenth ++)
		for (int i = 1; i <= n - lenth +  1; i ++)
		{
			int j = i + lenth - 1;
			for (int k = i; k <= j; k ++)
				f[i][j] = min(f[i][j], 
					f[i][k] + f[k + 1][j] + stone[j] - stone[i - 1]);
		}
	printf("%d", f[1][n]);
	return 0;
}
