/*

*/
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2010;
int n, cnt, head;
int next[maxn];
int m[maxn];
int v[maxn];
char ch;
void out(){
	for(int i = next[head]; i != -1; i = next[i]){
		printf("%d %d\n", m[i], v[i]);
	}
}
int main(){
	next[0] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &m[i], &v[i]);
		next[i] = i + 1;
	}
	next[n] = -1;
	scanf("%d", &cnt);
	while(cnt--){
		cin >> ch;
		int cur = head;
		switch(ch){
			case 'E':
				int ll, rr, summ, sumv;
				scanf("%d%d", &ll, &rr);
				for(int i = 0; i < ll; i++) cur = next[cur];
				summ = sumv = 0;
				for(int i = ll; i <= rr; i++){
					summ += m[cur]; sumv += v[cur];
					cur = next[cur];
				}
				printf("%.3lf\n", (double)summ / sumv);
				break;
			case 'I':
				int pos;
				n++;
				scanf("%d%d%d", &pos, &m[n], &v[n]);
				for(int i = 0; i < pos; i++) cur = next[cur];
				next[n] = next[cur]; next[cur] = n;
				break;
			case 'D':
				int x;
				scanf("%d", &x);
				for(int i = 1; i < x; i++) cur = next[cur];
				next[cur] = next[next[cur]];
				break;
		}
		//out();
	}
	return 0;
}
