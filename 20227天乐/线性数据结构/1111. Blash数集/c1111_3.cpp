/*
STL
用变量记下.front()，避免重复调用
976ms 4.36M 
*/
#include <cstdio>
#include <queue>
using namespace std;
int a, n;
queue<int> q2, q3;
int main(){
	while(scanf("%d%d", &a, &n) != -1){
		int cur = a;
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		q2.push(2 * a + 1);
		q3.push(3 * a + 1);
		for(int i = 2; i <= n; i++){
			int h2 = q2.front(), h3 = q3.front();
			if(h2 == h3){
				cur = h2;
				q2.pop(); q3.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}else if(h2 < h3){
				cur = h2;
				q2.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}else{
				cur = h3;
				q3.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}
		}
		printf("%d\n", cur);
	}
	return 0;
}
