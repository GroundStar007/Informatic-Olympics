#include<bits/stdc++.h>
using namespace std;
string s;
queue<int>order;
bool check() {
	stack<int> s;   //sÎªÄ£ÄâÕ»
	int n = order.size();
	for (int i = 1; i <= n; i++) {
		s.push(i);
		while (!s.empty() && s.top() == order.front()) {
			s.pop();
			order.pop();
		}
	}
	if (!s.empty()) {
		return false;
	}
	return true;
}
int main(){
  getline(cin,s);
  for(int i=0;i<s.length();i++)
  	order.push(s[i]);
  if(check())cout<<"yes";
  else cout<<"no";
  return 0;
}
