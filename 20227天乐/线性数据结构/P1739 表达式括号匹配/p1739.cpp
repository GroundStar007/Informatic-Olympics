#include <cstdio>
#include <stack>
using namespace std;
bool match=true;
char ch;
stack<char> st;
int main(){
	ch=getchar();
	while(ch!='@'){
		if(ch=='(') st.push(ch);
		else if(ch==')'){
			if(!st.empty()) st.pop();
			else{
				match=false; break;
			}
		}
		ch=getchar();
	}
	if(match&&st.empty()) printf("YES\n");
	else printf("NO\n");
	return 0;
} 

