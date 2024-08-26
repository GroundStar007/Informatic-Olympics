# include <iostream>
# include <cstdio>
using namespace std;
int n, a[200005], vis[200005];
int main ()
{
	freopen("fruit.in", "r", stdin);
	freopen("fruit.out", "w", stdout);
	scanf("%d", &n);
	int len = n;
	char c;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int h = 0;
	while (len)
	{
		int t = -1, f = 0;
		for (int i = 0; i < n; i++)
			if (a[i] != t && !vis[i])
			{
				if (t != -1) f = 1;
				t = a[i];
				vis[i] = 1;
				printf("%d ", i + 1);
				len--;
			}
		putchar('\n');
		if (f == 0)
		{
			for (int i = 0; i < n; i++)
				if (!vis[i])
					printf("%d\n", i + 1);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
