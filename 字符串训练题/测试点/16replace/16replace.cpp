#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string s,a,b;  
int k;  
int main()
{  
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	getline(cin,s);//第1行是包含多个单词的字符串 s 	
	cin>>a;	
	cin>>b;	
	a=" "+a+" ";
	b=" "+b+" ";
	s=" "+s+" ";
	k=s.find(a);	//find函数：查找第一次出现的目标字符串    //说明：如果查找成功则输出查找到的第一个位置，否则返回-1；		
	while(k!=-1)//这个就是查找成功 也就是返回值不是-1 
	{
		s.replace(k,a.size(),b);//将s中所有单词a替换成b之后的字符串。	
		k=s.find(a);//继续找 没有找到就跳出while循环 
	}
	s.erase(s.size()-1,1);
	s.erase(0,1);
	cout<<s<<endl;
	return 0 ;
}

