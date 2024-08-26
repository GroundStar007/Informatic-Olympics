#include <iostream>
#include <cstdio>
#include <algorithm>
int n,m,taps[10000];
using namespace std;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>taps[i];
	for(int i=m;i<n;i++)
	{
		sort(taps,taps+m);
		taps[0]+=taps[i];
	}
	sort(taps,taps+m,greater<int>());
	cout<<taps[0];
	return 0;
}
