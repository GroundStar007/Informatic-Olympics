/*
STL queue   TLE
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
			if(q2.front() == q3.front()){
				cur = q2.front();
				q2.pop(); q3.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}else if(q2.front() < q3.front()){
				cur = q2.front();
				q2.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}else{
				cur = q3.front();
				q3.pop();
				q2.push(2 * cur + 1);
				q3.push(3 * cur + 1);
			}
		}
		printf("%d\n", cur);
	}
	return 0;
}
