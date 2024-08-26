#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int f[5009][5009], n, a[5009], ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		f[i][i] = 1;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int  k = 1; k < i; k ++)
		{
			if(a[k] < a[i])
				f[i][i] = max(f[i][i], f[i - 1][a[k]] + 1);
		}
		ans = max(ans, f[i][i]);
	}
	printf("%d", ans);	
	return 0;
}
