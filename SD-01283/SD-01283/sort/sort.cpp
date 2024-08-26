#include <cstdio>
using namespace std;
#define maxn 8005 
int array[maxn];
int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", array + i);
	}
	for (int opt, x, v, ans, i = 1; i <= q; i++) {
		scanf("%d %d", &opt, &x);
		if (opt == 1) {
			scanf("%d", &v);
			array[x] = v;
		} else {
			ans = 0;
			for (int j = x; j >= 1; j--) {
				if (array[j] <= array[x]) {
					ans++;
				}
			}
			for (int j = x + 1; j <= n; j++) {
				if (array[j] < array[x]) {
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
复杂度: 
O(n(Q-count(operator1)))
把复杂度卡满是
1.6e9 
*/
// 76 分 
