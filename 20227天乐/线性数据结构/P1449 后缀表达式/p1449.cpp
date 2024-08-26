#include <cstdio>
#include <stack>
using namespace std;
char ch,op;
int x,y;
stack<int> st;
int main(){
	ch=getchar();
	while(ch!='@'){
		if(ch>='0'&&ch<='9'){
			x=0;
			while(ch!='.'){
				x=x*10+ch-'0';
				ch=getchar();
			}
			st.push(x);
		}else{	//ÔËËã·ûºÅ 
			x=st.top(); st.pop();
			y=st.top(); st.pop();
			switch(ch){
				case '+': st.push(y+x); break;
				case '-': st.push(y-x); break;
				case '*': st.push(y*x); break;
				case '/': st.push(y/x); break;
			}
		}
		ch=getchar();
	}
	printf("%d\n",st.top());
	return 0;
}

