#include<iostream>
#include<string>
using namespace std;
string Date,Month,Day,Year,NewDate;
int i,k;
int main()
{
	freopen("date5.in","r",stdin);
	freopen("date5.out","w",stdout);
    getline(cin,Date,'\n');
    i=Date.find(" ");
    Month=Date.substr(0,i);
    k=Date.find(",");
    Day=Date.substr(i+1,k-i-1);
    Year=Date.substr(k+1,4);
    NewDate=Day+" "+Month+" "+Year;
    cout<<NewDate;
}
