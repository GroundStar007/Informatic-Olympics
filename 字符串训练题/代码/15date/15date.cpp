#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
string Date,Month,Year,Day;
int i,k;
int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	getline(cin,Date);
	i=Date.find(" ");
	Month=Date.substr(0,i);
	k=Date.find(",");
	Day=Date.substr(i+1,k-i-1);
	Year=Date.substr(k+2,Date.size()-1);
	cout<<Day<<" "<<Month<<" "<<Year;
	return 0;
}
