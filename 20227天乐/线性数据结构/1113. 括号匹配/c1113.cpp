/*

*/
#include <cstdio>
const int maxl = 110;
char ss[maxl];
int st[maxl], top;
int main(){
	scanf("%s", ss);
	for(int i = 0; ss[i]; i++){
		if(ss[i] == '(') st[top++] = i;
		else printf("%d %d\n", st[--top], i);
	}
	return 0;
}
