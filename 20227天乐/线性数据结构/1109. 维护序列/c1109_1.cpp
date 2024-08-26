/*

*/
#include <cstdio>
const int maxn = 2010;
int n, m, a[maxn];
int op, x, y;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	while(m--){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &x);
			printf("%d\n", a[x - 1]);
		}else if(op == 2){
			scanf("%d%d", &x, &y);
			for(int i = n; i >= x; i--) a[i] = a[i - 1];
			a[x - 1] = y; n++;
		}else{
			scanf("%d", &x);
			for(int i = x; i < n; i++) a[i - 1] = a[i];
			n--;
		}
	}
	return 0;
} 
