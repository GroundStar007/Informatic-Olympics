/*

*/
#include <cstdio>
const int maxn = 1010;
int t, n, a[maxn];
int st[maxn], top, cur;
bool ok;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		top = 0; cur = 1; ok = true;
		for(int i = 0; i < n; i++){
			while(cur <= a[i]) st[top++] = cur++;
			if(st[top - 1] == a[i]) top--;
			else{
				ok = false; break;
			}
		}
		if(ok) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
} 
