#include <cstdio>
using namespace std;
int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	int ans = 0;
	if (l / n != r / n) {
		ans = n - 1;
	} else {
		ans = r % n;
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 100 ·Ö 
