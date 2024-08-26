/*
手工队列 56ms 7.83M 
*/
#include <cstdio>
const int maxl = 1000010;
int a, n;
int que2[maxl], que3[maxl];
int head2, tail2, head3, tail3;
int main(){
	while(scanf("%d%d", &a, &n) != -1){
		int cur = a;
		head2 = tail2 = head3 = tail3 = 0;
		que2[tail2++] = 2 * a + 1;
		que3[tail3++] = 3 * a + 1;
		for(int i = 2; i <= n; i++){
			if(que2[head2] == que3[head3]){
				cur = que2[head2];
				head2++; head3++;
				que2[tail2++] = 2 * cur + 1;
				que3[tail3++] = 3 * cur + 1;
			}else if(que2[head2] < que3[head3]){
				cur = que2[head2++];
				que2[tail2++] = 2 * cur + 1;
				que3[tail3++] = 3 * cur + 1;
			}else{
				cur = que3[head3++];
				que2[tail2++] = 2 * cur + 1;
				que3[tail3++] = 3 * cur + 1;
			}
		}
		printf("%d\n", cur);
	}
	return 0;
}
