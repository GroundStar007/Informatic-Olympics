#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string line;
int main(){
	while(getline(cin,line)){
		string ans(line.size(),' ');
		stack<int> st;
		for(int i=0;i<line.size();i++){
			if(line[i]=='('){
				st.push(i); ans[i]='$';
			}else if(line[i]==')'){
				if(!st.empty()){
					ans[st.top()]=' ';
					st.pop();
				}else ans[i]='?';
			}
		}
		cout<<line<<endl<<ans<<endl;
	}
	
	return 0;
}

