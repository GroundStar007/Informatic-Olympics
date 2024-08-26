#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
int L, S, T, M, stone, f[100000009];
bool IsStone[1000009];
int main()
{
	scanf("%d%d%d%d", &L, &S, &T, &M);
	for (int i = 1; i <= M; i ++)
	{
		scanf("%d", &stone);
		IsStone[stone] = true;
	}
	for (int i = 1; i <= L; i ++)
	{
		f[i] = 0x3f3f3f3f;
		for (int j = S; j <= T; j ++)
		{
			if(i - j >= 0)
				if(IsStone[i] == true)
					f[i] = min(f[i], f[i - j] + 1);
				else f[i] = min(f[i], f[i - j]);
		}
	}
	printf("%d", f[L]);
	return 0;
}
