#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<int>k;
char t;
int summ,a,b;

void Calculate(char ope){
	a=k.top(),k.pop();
	b=k.top(),k.pop();
	if(ope=='+')k.push(a+b);
	if(ope=='-')k.push(b-a);
	if(ope=='*')k.push(a*b);
	if(ope=='/')k.push(a/b);
}

int main(){
	freopen("1.txt","r",stdin);
	while(cin>>t&&t!='@'){
		if(t>='0'&&t<='9'){
			summ=summ*10+(t-'0');
			while(cin>>t&&t!='.')
				summ=summ*10+(t-'0');
			k.push(summ);
			summ=0;
		}
		else Calculate(t);
	}
	cout<<k.top();
}

