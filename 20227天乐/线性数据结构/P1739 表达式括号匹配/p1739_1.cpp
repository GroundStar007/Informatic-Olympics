/*

*/
#include <cstdio>
#include <stack>
using namespace std;
const int maxl=260;
char ss[maxl];
stack<char> st;
char ch;
bool flag;
int main(){
	flag=true;
	scanf("%s",ss);
	for(int i=0;ss[i]!='@';i++){
		if(ss[i]=='(') st.push(ss[i]);
		else if(ss[i]==')'){
			if(st.empty()){
				flag=false; break;
			}else st.pop();
		}
	}
	flag=flag&&st.empty();
	if(flag) printf("YES\n");
	else printf("NO\n");
}
