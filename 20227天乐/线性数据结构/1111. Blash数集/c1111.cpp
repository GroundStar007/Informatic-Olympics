/*

*/
#include <cstdio>
const int maxn = 1000010;
int q[maxn];
int a, n, two, three;
int main(){
	while(scanf("%d%d", &a, &n) != -1){
		q[0] = a; two = three = 0;
		for(int i = 1; i < n; i++){
			if(2 * q[two] + 1 == 3 * q[three] + 1){
				q[i] = 2 * q[two] + 1;
				two++; three++; 
			}else if(2 * q[two] + 1 < 3 * q[three] + 1){
				q[i] = 2 * q[two] + 1;
				two++;
			}else{
				q[i] = 3 * q[three] + 1;
				three++;
			}
		}
		printf("%d\n", q[n - 1]);
	}
	return 0;
} 
