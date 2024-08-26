/*

*/
#include <cstdio>
const int maxn = 2010;
int n, m, a[maxn];
int next[maxn], first;
int op, x, y;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		next[i] = i + 1;
	}
	next[n - 1] = -1;
	scanf("%d", &m);
	while(m--){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &x);
			int i = first, cnt = 1;
			for(; cnt < x; i = next[i], cnt++);
			printf("%d\n", a[i]);
		}else if(op == 2){
			scanf("%d%d", &x, &y);
			a[n++] = y;
			if(x == 1){
				next[n - 1] = first; first = n - 1;
			}else{
				int i = first, cnt = 1;
				for(; cnt < x - 1; cnt++, i = next[i]);
				next[n - 1] = next[i];
				next[i] = n - 1;
			}
		}else{
			scanf("%d", &x);
			if(x == 1) first = next[first];
			else{
				int i = first, cnt = 1;
				for(; cnt < x - 1; cnt++, i = next[i]);
				next[i] = next[next[i]];
			}
		}
	}
	return 0;
}
