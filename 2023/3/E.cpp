#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string n,sp;
int s,l;
bool f=false;

int main(){
	cin>>n>>s;
	while(s--){
		f=false;
		for(int i=0;i<n.size()-1;i++)
			if(n[i]>n[i+1]){
				n.erase(i,1);
				f=true;
				break;
			}
		if(f==false)n.erase(n.size()-1,1);
	}

	cout<<n;
	return 0;
}
