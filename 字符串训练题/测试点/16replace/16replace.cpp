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
	getline(cin,s);//��1���ǰ���������ʵ��ַ��� s 	
	cin>>a;	
	cin>>b;	
	a=" "+a+" ";
	b=" "+b+" ";
	s=" "+s+" ";
	k=s.find(a);	//find���������ҵ�һ�γ��ֵ�Ŀ���ַ���    //˵����������ҳɹ���������ҵ��ĵ�һ��λ�ã����򷵻�-1��		
	while(k!=-1)//������ǲ��ҳɹ� Ҳ���Ƿ���ֵ����-1 
	{
		s.replace(k,a.size(),b);//��s�����е���a�滻��b֮����ַ�����	
		k=s.find(a);//������ û���ҵ�������whileѭ�� 
	}
	s.erase(s.size()-1,1);
	s.erase(0,1);
	cout<<s<<endl;
	return 0 ;
}

